#include <stdio.h>

void increment() {
    static int counter = 0;  // 局部静态变量，只初始化一次
    counter++;
    printf("counter = %d\n", counter);
}

int main() {
    increment();
    increment();
    increment();
    return 0;
}
