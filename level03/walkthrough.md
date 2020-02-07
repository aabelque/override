The binary waits for a number that will be substracted to a constant number, and if its less or equal to 21, it will call the `decrypt` funtion with the result of the substraction. It also contains a switch statement, which holds a list of values that can be constantly passed into the decrypt function. \
When disassembling, we see decrypt xor's a string in a loop we got from the following script (because it was written in hexadecimal in the assembly code so we had to decode it):
```python
import struct

b32 = lambda x: struct.pack("I", x)
a = [0x757c7d51, 0x67667360, 0x7b66737e, 0x33617c7d]

s = "".join([b32(c) for c in a])

print(s)
```
Testing a few values, we can type `322424827` and it will give us a shell:
```shell
bash$ ./level3
***********************************
*               level03         **
***********************************
Password:322424827
$ cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
```

