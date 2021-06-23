# import uuid
#
# test_shell = b"\xfc\xe8\xfc\xe8\xfc\xe8\xfc\xe8\xfc\xe8\xfc\xe8\xfc\xe8\xfc\xe8"
# print(uuid.UUID(bytes=test_shell))
import uuid
import binascii
shellcode = b""

hex = binascii.hexlify(shellcode).decode()
hex += '0' * (32 - (len(hex) % 32))
for i in range(0,len(hex),32):
    print("\"{}\",".format(uuid.UUID(bytes_le=binascii.unhexlify(hex[i:i+32]))))
