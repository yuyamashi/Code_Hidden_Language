#include <stdio.h>

int main() {
    int a = 0;
    int b = 1;

    // Logic gates
    int gate1 = a || b;
    int gate2 = !(a && b);
    int sum = gate1 && gate2;
    int carry = a && b;

    printf("Sum: %d\n", sum);
    printf("Carry: %d\n", carry);

    return 0;
}