#include <stdio.h>

static int counter = 0; // 全局静态变量

void increment() {
    counter++;
    printf("counter = %d\n", counter);
}

int main() {
    increment();
    increment();
    return 0;
}
