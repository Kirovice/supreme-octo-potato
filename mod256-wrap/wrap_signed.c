#include <stdio.h>

int main() {
    signed char x = 127;  // signed char 最大值

    printf("x = %d\n", x);       // 输出：127

    x = x + 1;
    printf("x + 1 = %d\n", x);   // 输出：-128

    x = x + 1;
    printf("x + 2 = %d\n", x);   // 输出：-127

    return 0;
}
