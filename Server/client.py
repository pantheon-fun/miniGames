import socket

sock = socket.socket()
sock.connect(('10.0.0.41', 1001))
sock.send('pantheon'.encode())
print("Sent")
data = sock.recv(1024).decode()
while data != 'end':
    print(data)
    dat = input()
    sock.send(dat.encode())
    data = sock.recv(1024).decode()
sock.close()

print(data)
