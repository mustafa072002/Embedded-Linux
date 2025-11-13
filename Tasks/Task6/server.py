#!/usr/bin/env python3

import socket

server_socket = socket.socket(socket.AF_INET , socket.SOCK_STREAM)

server_socket.bind(("127.0.0.1" , 5000))
server_socket.listen(5)
print("Server is listening on port 5000...")

try:
    while True:
        client_socket , client_address = server_socket.accept()
        print(f"Connection from {client_address} has been established!")
        data = client_socket.recv(1024)
        a ,op, b = data.decode().split()
        print(f"Received {a} , {op} , {b} From Client with {client_address}")
        a = int(a)
        b = int(b)
        if op == '+':
            result = a + b
        elif op == '-':
            result = a - b
        elif op == '*':
            result = a * b
        elif op == '/':
            if b != 0:
              result = a / b
            else:
                result = "Error: divide by zero"
        else:
            result = "Invalid operator"
        client_socket.send(str(result).encode())

except KeyboardInterrupt:
    print("Server shutting down...")
finally:
    server_socket.close()

    