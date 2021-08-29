"""
commands handler

args:
    text, put by player
return:
    text, to put out
"""
#  Commands
def help2(args=[], kwargs={}):
    str = 'Called help with arguments:'
    for i in args:
        str += " " + i + ","
    for i in kwargs:
        str += "\n" + i + ": " + kwargs[i]
    return str


commands = {"help": help2}


#  Handler
def handler(text=''):
    text = text.split(" ")
    command = text[0]
    print(command)
    args = []
    kwargs = {}
    i = 1
    while i != len(text):
        if text[i][0] != '-':
            args.append(text[i])
            i += 1
        else:
            kwargs[text[i]] = text[i+1]
            i += 2
    if command in commands:
        print(command + " run")
        return commands[command](args, kwargs)
    return "no handler"
