import socket

server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
ip='127.0.0.1'
port=4421
server.bind((ip,port))
server.listen(5)
print("Server listning....")

while True:
    client,addr=server.accept()
    print(f"Connected to client -> {addr}")
    msg=client.recv(1024).decode().upper();
    client.send(msg.encode())
    client.close()
    break