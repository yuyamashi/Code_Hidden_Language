#include <stdio.h>

int main() {
    int a = 1;
    int b = 1;

    // Logic gates
    int gate1 = a || b;
    int gate2 = !(a && b);
    int sum = gate1 && gate2;

    printf("Sum: %d\n", sum);

    return 0;
}