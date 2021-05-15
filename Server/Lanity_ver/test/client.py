import socket
from os import _exit


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('localhost', 10596))
sock.send('Home PC'.encode())
data = ''
while data != 'EOP':
    data = input('Enter data: ')
    sock.send(data.encode())
    if data == 'x':
        _exit(1)
