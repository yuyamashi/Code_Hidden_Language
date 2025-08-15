#include <stdio.h>

// XOR gate
int xor_gate(int input1, int input2) {
    return (input1 || input2) && !(input1 && input2);
}

// NAND gate
int nand_gate(int input1, int input2) {
    return !(input1 && input2);
}

// AND gate
int and_gate(int input1, int input2) {
    return input1 && input2;
}

// OR gate
int or_gate(int input1, int input2) {
    return input1 || input2;
}

// Function to calculate sum (difference) and carry for half adder
void half_block(int input1, int input2, int *sum, int *carry) {
    *sum = and_gate(or_gate(input1, input2), nand_gate(input1, input2));
    *carry = and_gate(input1, input2);
}

// Function to calculate sum (difference) and carry for full adder
void full_block(int input1, int input2, int subt, int carry_in, int *sum, int *carry) {
    int sum1, carry1, carry2;
    half_block(input1, xor_gate(subt, input2), &sum1, &carry1);
    half_block(sum1, carry_in, sum, &carry2);
    *carry = or_gate(carry1, carry2);
}

// Function to calculate sum (difference) and carry for eight bit adder
void eight_bit_adder_subtractor(int a[8], int b[8], int subt, int sum[8], int *carry_out) {
    int carry = subt;
    for (int i = 7; i >= 0; i--) {
        full_block(a[i], b[i], subt, carry, &sum[i], &carry);
    }
    *carry_out = xor_gate(subt, carry);
}

// Main function to test the eight bit adder
int main() {
    int a[8] = {1, 0, 1, 0, 1, 0, 1, 0};
    int b[8] = {0, 1, 0, 1, 1, 1, 1, 1};
    int subt = 1; // 1: subtractor, 0: adder

    int sum[8], carry;
    eight_bit_adder_subtractor(a, b, subt, sum, &carry);

    printf("Sum/Difference: %d", carry);
    for (int i = 0; i <= 7; i++) {
        printf("%d", sum[i]);
    }
    printf("\n");

    return 0;
}