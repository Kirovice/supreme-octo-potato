#include <stdio.h>

int main() {
    int x = -107;

    printf("原始值 x = %d\n", x);
    printf("二进制（32位）表示：\n");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n\n");

    // 左移
    int left = x << 4;
    printf("x << 4 = %d\n", left);

    // 逻辑右移：先转换为 unsigned int
    unsigned int ux = (unsigned int)x;
    unsigned int logical = ux >> 4;
    printf("逻辑右移 ux >> 4 = %u\n", logical);

    // 算术右移：直接用 int 类型
    int arith = x >> 4;
    printf("算术右移 x >> 4 = %d\n", arith);

    return 0;
}
