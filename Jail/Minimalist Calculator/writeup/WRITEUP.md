# How to Solve

Calling the `eval` function without specifying globals and locals means that all variables outside the `eval` (the main program) are the same variables and can be accessed inside the `eval`. In addition, we can also override the value of these variables. Therefore, we only need to override the `type` function to be a function that returns the `int` class by utilizing the walrus operator.

```py
>> (type:=lambda x:int,flag)
```

Alternatively, we can override the `int` class to be the `tuple` class.

```py
>> (tuple:=int,flag)
```
