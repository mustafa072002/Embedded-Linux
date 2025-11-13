#!/usr/bin/env python3

import socket

client_socket = socket.socket(socket.AF_INET , socket.SOCK_STREAM)

try:
    client_socket.connect(("127.0.0.1" , 5000))
except ConnectionRefusedError:
    print("Unable to connect to the server. Is it running?")
    exit(1)

print("Enter two numbers And The Operation:")
a = input("First number: ")
op = input("Choose +  -  * / : ")
b = input("Second number: ")

client_socket.sendall(f"{a} {op} {b}".encode())

data = client_socket.recv(1024)
result = int(data.decode().strip())
print(f"Result is : {result}")


