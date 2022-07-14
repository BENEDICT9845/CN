import socket

server=socket.socket()
ip='127.0.0.1'
port=4421
server.connect((ip,port))

str=input("Enter text: ")
server.send(str.encode())
nstr=server.recv(1024).decode()

print(f"Response from server: {nstr}")
