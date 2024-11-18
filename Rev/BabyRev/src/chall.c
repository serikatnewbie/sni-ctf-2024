#include <stdio.h>
#include <string.h>

const char key[] = "SerikatNewbieIndonesia";

int main()
{
    FILE *file = fopen("flag.txt", "r");
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char flag[size];

    fread(flag, 1, size, file);
    flag[size - 1] = '\0';

    int len = strlen(flag);

    int left = 1;
    int right = (len % 2 == 0) ? len - 1 : len - 2;

    while (left < right)
    {
        char temp = flag[left];
        flag[left] = flag[right];
        flag[right] = temp;
        left += 2;
        right -= 2;
    }

    int key_len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        if (i > 0)
        {
            putchar(' ');
        }
        int j = i % key_len;
        char a = flag[i];
        char b = key[j];
        printf("%hhd", a ^ b);
    }
    putchar('\n');

    fclose(file);
    return 0;
}
