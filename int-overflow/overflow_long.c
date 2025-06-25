#include <stdio.h>

int main() {
    // 原始的 int（32 位）
    int a = 200;
    int b = 300;
    int c = 400;
    int d = 500;

    int result_int = a * b * c * d;
    printf("【int 结果】       %d\n", result_int);

    // 使用 long long（64 位整数）
    long long result_ll = (long long)a * b * c * d;
    printf("【long long 结果】%lld\n", result_ll);

    // 使用 unsigned int 查看“补码原始值”
    unsigned int result_unsigned = a * b * c * d;
    printf("【unsigned 结果】  %u\n", result_unsigned);

    return 0;
}
