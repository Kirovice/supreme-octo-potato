#include <stdio.h>

int counter = 0; // 全局变量

void increment() {
    counter++;
    printf("counter = %d\n", counter);
}

int main() {
    increment();
    increment();
    return 0;
}
