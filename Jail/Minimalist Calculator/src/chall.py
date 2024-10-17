#!/usr/bin/env python3

from secret import flag


def check(s):
    blacklisted = [
        "breakpoint",
        "print",
        "input",
        "eval",
        "exec",
        "open",
        "__import__",
        "globals",
        "locals",
        "vars",
    ]
    return not any(x in s for x in blacklisted)


expression = input(">> ")
if len(expression) > 25 or not expression.isascii() or not check(expression):
    print("lol")
    exit(-1)
try:
    result = eval(expression)
except:
    print("lol")
    exit(-1)
if type(result) is int or type(result) is float:
    print(result)
else:
    print("lol")
    exit(-1)
