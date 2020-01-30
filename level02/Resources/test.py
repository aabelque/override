#!/usr/bin/env python

import struct

b64 = lambda x: struct.pack("Q", x);
password = ""
values = [0x756e505234376848, 0x45414a3561733951, 0x377a7143574e6758, 0x354a35686e475873, 0x48336750664b394d]

for hex_value in values:
    password = password + b64(hex_value))

print(password)

