import tkinter as tk
import commands
DEBUG = True


#  DEBUG settings
def debug(level, message):
    if not DEBUG:
        return
    print(level + ": ")
    print(message)


#  TKinter settings
root = tk.Tk()
root.title("Pantheon CtrlTerm")
root.geometry("1024x768")
root.resizable(False, False)


#  Terminal settings
INPUT_STR = "@Pantheon > "
terminal = tk.Text(root)
terminal.config(bg="#111111", fg="#dd0910", exportselection=False, cursor="man",
                insertbackground="#ff0505", insertontime=800, insertofftime=100,
                wrap=tk.WORD, insertwidth=4)
terminal.place(x=0, y=0, height=768, width=1024)


#  command handler
def handle(event):
    text = terminal.get("end - 2 lines + " + str(len(INPUT_STR)) + "c", "end").replace("\n", '')
    debug("text", text)
    terminal.insert("insert", commands.handler(text) + "\n")
    terminal.insert("insert", INPUT_STR)
    terminal.delete("insert", "end")


#Main loop
terminal.insert("insert", INPUT_STR)
root.attributes("-topmost", True)
terminal.focus_force()
root.bind("<Return>", handle)
root.mainloop()

