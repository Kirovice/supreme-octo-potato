#include <stdio.h>

void increment() {
    int counter = 0;  // 局部变量：每次调用函数时都会重新创建
    counter++;
    printf("counter = %d\n", counter);
}

int main() {
    increment();
    increment();
    increment();
    return 0;
}
