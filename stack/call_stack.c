#include <stdio.h>

void func2(int x) {
    int b = x + 1;
    printf("In func2: x = %d, b = %d\n", x, b);
}

void func1() {
    int a = 42;
    printf("In func1: a = %d\n", a);
    func2(a);
}

int main() {
    printf("In main\n");
    func1();
    return 0;
}
