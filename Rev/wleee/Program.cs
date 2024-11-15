using System;

// FLAG: flag{Flab8bByy_B1rDddd...:)}
class Program
{
    public delegate bool Checker();
    public delegate Checker CheckerCallback(string _);

    static Checker checker1(string flag)
    {
        int correct_number = 0;
        int[][] arr = [[], [], [5, 37], [15, 19, 22, 24, 26, 30, 34], [1, 2, 4, 18, 40], [0, 6, 13, 20, 25, 28, 29, 35], [7, 8, 10, 11, 16, 17, 21, 23, 31, 32, 33, 36, 38, 39], [3, 9, 12, 14, 27, 41]];
        for (int i = 0; i < arr.Length; i++)
        {
            for (int j = 0; j < arr[i].Length; j++)
            {
                if (flag.Length <= arr[i][j]) return () => false;
                correct_number += (int)flag[arr[i][j]] >> 4 == i ? 1 : 0;
            }
        }

        return () => correct_number == flag.Length;
    }

    static Checker checker2(string flag)
    {
        int correct_number = 0;
        int[][] arr = [[15, 22, 26, 30, 34, 37], [0, 4, 5, 14, 19, 24, 27, 29, 36], [7, 9, 11, 12], [17, 21, 38, 39, 40], [2], [3], [18, 23, 41], [1, 6, 8, 10, 13, 16, 20, 25, 28, 31, 32, 33, 35]];
        for (int i = 0; i < arr.Length; i++)
        {
            for (int j = 0; j < arr[i].Length; j++)
            {
                if (flag.Length <= arr[i][j]) return () => false;
                correct_number += (((int)flag[arr[i][j]] >> 1) & 0b111) == i ? 1 : 0;
            }
        }

        return () => correct_number == flag.Length;
    }
    static Checker checker3(string flag)
    {
        int correct_number = 0;
        int[][] arr = [[1, 7, 9, 10, 12, 16, 18, 21, 23, 30, 34, 36], [0, 2, 3, 4, 5, 6, 8, 11, 13, 14, 15, 17, 19, 20, 22, 24, 25, 26, 27, 28, 29, 31, 32, 33, 35, 37, 38, 39, 40, 41]];
        for (int i = 0; i < arr.Length; i++)
        {
            for (int j = 0; j < arr[i].Length; j++)
            {
                if (flag.Length <= arr[i][j]) return () => false;
                correct_number += ((int)flag[arr[i][j]] & 0b1) == i ? 1 : 0;
            }
        }

        return () => correct_number == flag.Length;
    }
    static void Main()
    {
        CheckerCallback[] checkerFunctionList = new CheckerCallback[]
        {
            (string flag) => checker1(flag),
            (string flag) => checker2(flag),
            (string flag) => checker3(flag),
        };

        Console.Write("Enter the flag: ");
        string flag = Console.ReadLine();

        foreach (var checkerCallback in checkerFunctionList)
        {
            if (!checkerCallback(flag)())
            {
                Console.WriteLine("Incorrect!!");
                System.Environment.Exit(1);
            }
        }
        Console.WriteLine("Correct!!");
    }
}