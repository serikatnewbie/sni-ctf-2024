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

typedef u8 (*operation)(u8, u8);

u8 input_0;
u8 input_1;
u8 input_2;
u8 input_3;
u8 input_4;
u8 input_5;
u8 input_6;
u8 input_7;
u8 input_8;
u8 input_9;
u8 input_10;
u8 input_11;
u8 input_12;
u8 input_13;
u8 input_14;
u8 input_15;
u8 input_16;
u8 input_17;
u8 input_18;
u8 input_19;
u8 input_20;
u8 input_21;
u8 input_22;
u8 input_23;
u8 input_24;
u8 input_25;
u8 input_26;
u8 input_27;
u8 input_28;
u8 input_29;
u8 input_30;
u8 input_31;

void write_48()
{
    putchar(48);
}
void write_49()
{
    putchar(49);
}
void write_50()
{
    putchar(50);
}
void write_51()
{
    putchar(51);
}
void write_52()
{
    putchar(52);
}
void write_53()
{
    putchar(53);
}
void write_54()
{
    putchar(54);
}
void write_55()
{
    putchar(55);
}
void write_56()
{
    putchar(56);
}
void write_57()
{
    putchar(57);
}
void write_97()
{
    putchar(97);
}
void write_98()
{
    putchar(98);
}
void write_99()
{
    putchar(99);
}
void write_100()
{
    putchar(100);
}
void write_101()
{
    putchar(101);
}
void write_102()
{
    putchar(102);
}
void write_103()
{
    putchar(103);
}
void write_104()
{
    putchar(104);
}
void write_105()
{
    putchar(105);
}
void write_106()
{
    putchar(106);
}
void write_107()
{
    putchar(107);
}
void write_108()
{
    putchar(108);
}
void write_109()
{
    putchar(109);
}
void write_110()
{
    putchar(110);
}
void write_111()
{
    putchar(111);
}
void write_112()
{
    putchar(112);
}
void write_113()
{
    putchar(113);
}
void write_114()
{
    putchar(114);
}
void write_115()
{
    putchar(115);
}
void write_116()
{
    putchar(116);
}
void write_117()
{
    putchar(117);
}
void write_118()
{
    putchar(118);
}
void write_119()
{
    putchar(119);
}
void write_120()
{
    putchar(120);
}
void write_121()
{
    putchar(121);
}
void write_122()
{
    putchar(122);
}
void write_65()
{
    putchar(65);
}
void write_66()
{
    putchar(66);
}
void write_67()
{
    putchar(67);
}
void write_68()
{
    putchar(68);
}
void write_69()
{
    putchar(69);
}
void write_70()
{
    putchar(70);
}
void write_71()
{
    putchar(71);
}
void write_72()
{
    putchar(72);
}
void write_73()
{
    putchar(73);
}
void write_74()
{
    putchar(74);
}
void write_75()
{
    putchar(75);
}
void write_76()
{
    putchar(76);
}
void write_77()
{
    putchar(77);
}
void write_78()
{
    putchar(78);
}
void write_79()
{
    putchar(79);
}
void write_80()
{
    putchar(80);
}
void write_81()
{
    putchar(81);
}
void write_82()
{
    putchar(82);
}
void write_83()
{
    putchar(83);
}
void write_84()
{
    putchar(84);
}
void write_85()
{
    putchar(85);
}
void write_86()
{
    putchar(86);
}
void write_87()
{
    putchar(87);
}
void write_88()
{
    putchar(88);
}
void write_89()
{
    putchar(89);
}
void write_90()
{
    putchar(90);
}
void write_33()
{
    putchar(33);
}
void write_34()
{
    putchar(34);
}
void write_35()
{
    putchar(35);
}
void write_36()
{
    putchar(36);
}
void write_37()
{
    putchar(37);
}
void write_38()
{
    putchar(38);
}
void write_39()
{
    putchar(39);
}
void write_40()
{
    putchar(40);
}
void write_41()
{
    putchar(41);
}
void write_42()
{
    putchar(42);
}
void write_43()
{
    putchar(43);
}
void write_44()
{
    putchar(44);
}
void write_45()
{
    putchar(45);
}
void write_46()
{
    putchar(46);
}
void write_47()
{
    putchar(47);
}
void write_58()
{
    putchar(58);
}
void write_59()
{
    putchar(59);
}
void write_60()
{
    putchar(60);
}
void write_61()
{
    putchar(61);
}
void write_62()
{
    putchar(62);
}
void write_63()
{
    putchar(63);
}
void write_64()
{
    putchar(64);
}
void write_91()
{
    putchar(91);
}
void write_92()
{
    putchar(92);
}
void write_93()
{
    putchar(93);
}
void write_94()
{
    putchar(94);
}
void write_95()
{
    putchar(95);
}
void write_96()
{
    putchar(96);
}
void write_123()
{
    putchar(123);
}
void write_124()
{
    putchar(124);
}
void write_125()
{
    putchar(125);
}
void write_126()
{
    putchar(126);
}
void write_32()
{
    putchar(32);
}
void write_9()
{
    putchar(9);
}
void write_10()
{
    putchar(10);
}
void write_13()
{
    putchar(13);
}
void write_11()
{
    putchar(11);
}
void write_12()
{
    putchar(12);
}

void test(operation op, u8 a, u8 b, u8 c)
{
    if (op(a, b) != c)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void assign_0()
{
    if (input_0 = getchar(), input_0 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_0()
{
    if (add(input_0, 224) != 71)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_1()
{
    if (input_1 = getchar(), input_1 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_1()
{
    if (add(input_1, 16) != 127)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_2()
{
    if (input_2 = getchar(), input_2 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_2()
{
    if (multiply(input_2, 53) != 233)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_3()
{
    if (input_3 = getchar(), input_3 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_3()
{
    if (subtract(input_3, 160) != 191)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_4()
{
    if (input_4 = getchar(), input_4 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_4()
{
    if (multiply(input_4, 101) != 135)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_5()
{
    if (input_5 = getchar(), input_5 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_5()
{
    if (multiply(input_5, 223) != 251)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_6()
{
    if (input_6 = getchar(), input_6 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_6()
{
    if (multiply(input_6, 87) != 83)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_7()
{
    if (input_7 = getchar(), input_7 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_7()
{
    if (multiply(input_7, 29) != 195)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_8()
{
    if (input_8 = getchar(), input_8 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_8()
{
    if (subtract(input_8, 239) != 131)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_9()
{
    if (input_9 = getchar(), input_9 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_9()
{
    if (subtract(input_9, 104) != 230)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_10()
{
    if (input_10 = getchar(), input_10 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_10()
{
    if (add(input_10, 149) != 247)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_11()
{
    if (input_11 = getchar(), input_11 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_11()
{
    if (subtract(input_11, 150) != 222)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_12()
{
    if (input_12 = getchar(), input_12 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_12()
{
    if (subtract(input_12, 157) != 198)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_13()
{
    if (input_13 = getchar(), input_13 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_13()
{
    if (subtract(input_13, 23) != 76)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_14()
{
    if (input_14 = getchar(), input_14 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_14()
{
    if (subtract(input_14, 185) != 168)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_15()
{
    if (input_15 = getchar(), input_15 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_15()
{
    if (add(input_15, 205) != 63)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_16()
{
    if (input_16 = getchar(), input_16 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_16()
{
    if (add(input_16, 174) != 43)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_17()
{
    if (input_17 = getchar(), input_17 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_17()
{
    if (add(input_17, 8) != 110)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_18()
{
    if (input_18 = getchar(), input_18 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_18()
{
    if (subtract(input_18, 191) != 176)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_19()
{
    if (input_19 = getchar(), input_19 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_19()
{
    if (multiply(input_19, 43) != 204)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_20()
{
    if (input_20 = getchar(), input_20 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_20()
{
    if (multiply(input_20, 157) != 26)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_21()
{
    if (input_21 = getchar(), input_21 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_21()
{
    if (add(input_21, 73) != 187)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_22()
{
    if (input_22 = getchar(), input_22 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_22()
{
    if (multiply(input_22, 29) != 195)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_23()
{
    if (input_23 = getchar(), input_23 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_23()
{
    if (subtract(input_23, 117) != 239)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_24()
{
    if (input_24 = getchar(), input_24 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_24()
{
    if (subtract(input_24, 213) != 154)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_25()
{
    if (input_25 = getchar(), input_25 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_25()
{
    if (add(input_25, 245) != 62)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_26()
{
    if (input_26 = getchar(), input_26 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_26()
{
    if (add(input_26, 5) != 119)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_27()
{
    if (input_27 = getchar(), input_27 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_27()
{
    if (multiply(input_27, 125) != 170)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_28()
{
    if (input_28 = getchar(), input_28 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_28()
{
    if (add(input_28, 178) != 5)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_29()
{
    if (input_29 = getchar(), input_29 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_29()
{
    if (add(input_29, 76) != 193)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_30()
{
    if (input_30 = getchar(), input_30 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_30()
{
    if (add(input_30, 233) != 92)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}
void assign_31()
{
    if (input_31 = getchar(), input_31 == '\n')
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

void test_31()
{
    if (add(input_31, 124) != 239)
    {

        write_87();
        write_114();
        write_111();
        write_110();
        write_103();
        write_10();

        exit(-1);
    }
}

int main()
{

    write_71();
    write_105();
    write_118();
    write_101();
    write_32();
    write_109();
    write_101();
    write_32();
    write_102();
    write_108();
    write_97();
    write_103();
    write_58();
    write_32();

    assign_28();
    assign_9();
    assign_25();
    assign_4();
    assign_24();
    assign_20();
    assign_17();
    assign_29();
    assign_31();
    assign_12();
    assign_14();
    assign_11();
    assign_5();
    assign_23();
    assign_22();
    assign_13();
    assign_1();
    assign_19();
    assign_2();
    assign_3();
    assign_0();
    assign_18();
    assign_6();
    assign_30();
    assign_7();
    assign_10();
    assign_26();
    assign_15();
    assign_27();
    assign_21();
    assign_8();
    assign_16();
    test_0();
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();
    test_10();
    test_11();
    test_12();
    test_13();
    test_14();
    test_15();
    test_16();
    test_17();
    test_18();
    test_19();
    test_20();
    test_21();
    test_22();
    test_23();
    test_24();
    test_25();
    test_26();
    test_27();
    test_28();
    test_29();
    test_30();
    test_31();

    write_67();
    write_111();
    write_114();
    write_114();
    write_101();
    write_99();
    write_116();
    write_10();

    return 0;
}

void __attribute__((constructor)) init()
{
    setbuf(stdout, NULL);
}
