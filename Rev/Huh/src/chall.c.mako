#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define u8 unsigned char

u8 negate(u8 b)
{
    u8 result = 0;
    for (int i = 0; i < 8; i++)
    {
        result |= (((b >> i) & 1) ^ 1) << i;
    }
    return result;
}

u8 subtract(u8 a, u8 b)
{
    u8 borrow;

    while (b != 0)
    {
        borrow = negate(a) & b;
        a = a ^ b;
        b = borrow << 1;
    }

    return a;
}

u8 add(u8 a, u8 b)
{
    u8 carry;
    while (b != 0)
    {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

u8 multiply(u8 a, u8 b)
{
    u8 result = 0;
    while (b > 0)
    {
        result = add(result, (b & 1) ? a : 0);
        a <<= 1;
        b >>= 1;
    }
    return result;
}
<%!
    import string
    import random
    import math
    flag = b"SNI{obfuscated_code_goes_brrrrr}"
    operations = [["add", "subtract", "multiply"][random.randint(0, 2)] for _ in range(len(flag))]
    order = list(range(len(flag)))
    random.shuffle(order)
    shuffled_flag = [flag[order[i]] for i in range(len(order))]
    operands = []
    ct = []
    for i in range(len(flag)):
        operands.append(random.randint(0, 255))
        if operations[i] == "add":
            ct.append((shuffled_flag[i] + operands[i]) % 256)
        elif operations[i] == "subtract":
            ct.append((shuffled_flag[i] - operands[i]) % 256)
        elif operations[i] == "multiply":
            while True:
                if math.gcd(operands[i], 256) == 1:
                    break
                operands[i] = random.randint(0, 255)
            ct.append((shuffled_flag[i] * operands[i]) % 256)
%>
typedef u8 (*operation)(u8, u8);

%for i in range(len(flag)):
u8 input_${i};
%endfor

%for i in string.printable.encode():
void write_${i}() {
    putchar(${i});
}
%endfor

<%def name="write(s)">
    %for i in s.encode():
    write_${i}();
    %endfor
</%def>

void test(operation op, u8 a, u8 b, u8 c) {
    if (op(a, b) != c) {
        ${write("Wrong\n")}
        exit(-1);
    }
}

%for i in range(len(flag)):
void assign_${i}() {
    if (input_${i} = getchar(), input_${i} == '\n') {
        ${write("Wrong\n")}
        exit(-1);
    }
}

void test_${i}() {
    if (${operations[i]}(input_${i}, ${operands[i]}) != ${ct[i]}) {
        ${write("Wrong\n")}
        exit(-1);
    }
}
%endfor

int main()
{
    ${write("Give me flag: ")}
    %for i in range(len(flag)):
    assign_${order.index(i)}();
    %endfor
    %for i in range(len(flag)):
    test_${i}();
    %endfor
    ${write("Correct\n")}
    return 0;
}

void __attribute__((constructor)) init () {
    setbuf(stdout, NULL);
}
