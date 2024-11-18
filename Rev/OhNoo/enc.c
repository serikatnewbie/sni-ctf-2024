#include <stdint.h>
#include <string.h>
#include <stdio.h>

void enc(uint8_t *buff, size_t n, uint8_t *key, size_t key_len) {
    char last = 0;
    size_t i = 0;
    for (; i < n; i++) {
        buff[i] ^= key[i % key_len];
        buff[i] *= 0x79;
        buff[i] ^= last;
        last = buff[i];
        buff[i] += 0x35 * (i + 1);
    }
    last = buff[n - (n / 2)];
    for (; i > 0; i--) {
        if (i < (n / 2)) {
            last = buff[n - 1];
        }
        buff[i] ^= last;
    }
    buff[0] ^= last;
}

int main() {
    uint8_t input[101];
    printf("Enter message: ");
    scanf("%100s", input);
    size_t len = strlen(input);
    input[len] = '\0';

    char key[12];
    key[0] = 0x23;
    key[2] = 0x12;
    key[4] = 0xe3;
    key[8] = 0xd3;
    key[9] = 0x02;
    key[1] = 0x42;
    key[5] = 0x40;
    key[6] = 0x12;
    key[3] = 0x3a;
    key[11] = 0xa;
    key[7] = 0x34;
    key[10] = 0x10;
    enc(input, len, key, 12);

    printf("result: ");
    for (int i = 0; i < len;i++) {
      if (input[i] < 0x10) {
        printf("0%x", input[i]);
      } else {
        printf("%x", input[i]);
      }
    }
  return 0;
}