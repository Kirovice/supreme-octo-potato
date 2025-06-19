#include <stdio.h>

int main() {
    int *ptr = (int *)0xC0000000;  // 尝试访问内核空间地址（示例地址）
    printf("Value at address 0xC0000000: %d\n", *ptr);
    return 0;
}
