#include <stdio.h>

int main() {
    double a = 3.14;
    double b = 1e20;

    double result1 = (a + b) - b;
    double result2 = a + (b - b);

    printf("(a + b) - b = %.20f\n", result1);
    printf("a + (b - b) = %.20f\n", result2);

    return 0;
}
