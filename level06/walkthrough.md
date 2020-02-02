We see the binary only passes an algorithm on our login input to compare with the serial, which would give us a shell in case the serial and the login hash is the same value.
```shell
(gdb) b *auth+114
(gdb) b *auth+286

(gdb) r
***********************************
*		level06		  *
***********************************
-> Enter Login: AAAAAA
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6
Breakpoint 1, 0x080487ba in auth ()

$ # avoid the ptrace call
(gdb) jump *auth+165
Breakpoint 2, 0x08048866 in auth ()

$ # get the value of 'v'
(gdb) x/wx $ebp-0x10
0xffffd688:	0x005f0c3a

(gdb) p 0x5f0c3a
$1 = 6229050

(gdb) quit

bash$ ./level06
***********************************
*		level06		  *
***********************************
-> Enter Login: AAAAAA
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6229050
Authenticated!

$ cat /home/users/level07/.pass
GbcPDRgsFK78LNnnuh7QyFYA2942Gp8yKj9KrWD8
```
