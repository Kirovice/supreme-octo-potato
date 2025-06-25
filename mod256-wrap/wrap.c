#include <stdio.h>

int main() {
    unsigned char x = 255;  // 8-bit 无符号整数

    printf("x = %u\n", x);      // 输出：255

    x = x + 1;
    printf("x + 1 = %u\n", x);  // 输出：0

    x = x + 1;
    printf("x + 2 = %u\n", x);  // 输出：1

    return 0;
}
