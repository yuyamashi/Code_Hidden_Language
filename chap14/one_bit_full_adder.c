#include <stdio.h>

// Function to calculate sum and carry for half adder using pointers
void half_block(int input1, int input2, int *sum, int *carry) {
    int gate1 = input1 || input2;
    int gate2 = !(input1 && input2);
    *sum = gate1 && gate2;
    *carry = input1 && input2;
}

int main() {
    int a = 1;
    int b = 1;
    int carry_in = 1;

    // First half block
    int sum1, carry1;
    half_block(a, b, &sum1, &carry1);

    // Second half block
    int sum2, carry2;
    half_block(sum1, carry_in, &sum2, &carry2);
    
    int sum = sum2;
    int carry = carry1 || carry2;

    printf("Sum: %d\n", sum);
    printf("Carry: %d\n", carry);

    return 0;
}