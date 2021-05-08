import socket

sock = socket.socket()
sock.bind(('10.0.0.13', 10596))
sock.listen(10)
conn, addr = sock.accept()

print ('connected: ', addr)
data = ''
while len(data) == 0 or data[0] != 'x':
    while True:
        data = conn.recv(1024)
        if not data:
            break
        conn.send(data.upper())
        data=data.decode()
        print(data)

conn.close()
