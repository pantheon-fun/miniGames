#
# Project name         guiServer
# Author:              Lanity Roshoose
# Date of mod.         15.05.2021
# Version              beta 2.050
#

import socket
import queue
from time import sleep as suck
from threading import Thread as dick
from os import _exit as exit
from appJar import gui


que = queue.Queue()


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('localhost', 10596))
sock.listen()


def handle(conn, addr, que):
    data = ''
    name = ''
    #Name get
    data = conn.recv(1024)
    if not data:
        return 'No name got'
    name = data.decode()
    print(name + " connected")
    que.put(name + " connected")
    while data[0] != 'x':
        data = conn.recv(1024).decode()
        if data == 'EOP':
            exit(2)
        if not data or data == 'x':
            que.put(name + " : Disconnected")
            return 0
        que.put(name + ' : ' + data)


def st_handle():
    while 'Pantheon is great':
        conn, addr = sock.accept()
        print("Connected")
        t = dick(target=handle, args=(conn, addr, que), daemon=True)
        t.start()


def data_print(que):
    messages = []
    while 'I love Pantheon':
        if que.empty():
            suck(0.5)
        else:
            messages.append(que.get())
            if len(messages) > 30:
                messages.pop(0)
            ret = ''
            for i in messages:
                ret += i + '\n'
            app.queueFunction(app.setMessage, "msgs", ret)


def exit_read():
    while 'Patheon is like 7734':
        data = input()
        print(data)
        if data == 'exit':
            print('exit?')
            exit(1)


#print_thr = dick(target=data_print, args=(que,), daemon=True)
#print_thr.start()
read_thr = dick(target=exit_read, daemon=True)
read_thr.start()
sthandle = dick(target=st_handle, daemon=True)
sthandle.start()
print("Program Pantheon minigames server a0.1 started")
app = gui()
app.setTitle("Pantheon internal server")
app.setSize("800x600")
app.setResizable(False)
app.setSticky('nw')
app.addEmptyMessage("msgs")
app.setMessageWidth("msgs", 600)
app.thread(data_print, que)
app.go()
