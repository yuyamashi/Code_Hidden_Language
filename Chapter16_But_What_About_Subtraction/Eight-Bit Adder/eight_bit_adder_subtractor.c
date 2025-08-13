#include <stdio.h>

// Function to calculate sum and carry for half adder
void half_block(int input1, int input2, int *sum, int *carry) {
    int gate1 = input1 || input2;
    int gate2 = !(input1 && input2);
    *sum = gate1 && gate2;
    *carry = input1 && input2;
}

// Function to calculate sum and carry for full adder
void full_block(int input1, int input2, int carry_in, int *sum, int *carry) {
    int sum1, carry1, carry2;
    half_block(input1, input2, &sum1, &carry1);
    half_block(sum1, carry_in, sum, &carry2);
    *carry = carry1 || carry2;
}

// Function to calculate sum and carry for eight bit adder
void eight_bit_adder(int a[8], int b[8], int carry_in, int sum[8], int *carry_out) {
    int carry = carry_in;
    for (int i = 7; i >= 0; i--) {
        full_block(a[i], b[i], carry, &sum[i], &carry);
    }
    *carry_out = carry;
}

// Main function to test the eight bit adder
int main() {
    int a[8] = {1, 0, 1, 0, 1, 0, 1, 0};
    int b[8] = {1, 0, 0, 1, 1, 0, 1, 0};

    int sum[8], carry;
    eight_bit_adder(a, b, 0, sum, &carry);

    printf("Sum: %d", carry);
    for (int i = 0; i <= 7; i++) {
        printf("%d", sum[i]);
    }
    printf("\n");

    return 0;
}