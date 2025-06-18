#include <stdio.h>

void increment() {
    static int counter = 0; // 静态变量：只初始化一次，保留上次的值
    counter++;
    printf("counter = %d\n", counter);
}

int main() {
    increment();
    increment();
    increment();
    return 0;
}
