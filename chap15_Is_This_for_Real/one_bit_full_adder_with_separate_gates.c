#include <stdio.h>

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

// Function to calculate sum and carry for half adder
void half_block(int input1, int input2, int *sum, int *carry) {
    *sum = and_gate(nand_gate(input1, input2), or_gate(input1, input2));
    *carry = and_gate(input1, input2);
}

// Function to calculate sum and carry for full adder
void full_block(int input1, int input2, int carry_in, int *sum, int *carry) {
    int sum1, carry1, carry2;
    half_block(input1, input2, &sum1, &carry1);
    half_block(sum1, carry_in, sum, &carry2);
    *carry = or_gate(carry1, carry2);
}

int main() {
    int a = 0, b = 1, carry_in = 1;
    
    int sum, carry;
    full_block(a, b, carry_in, &sum, &carry);

    printf("Sum: %d\n", sum);
    printf("Carry Out: %d\n", carry);

    return 0;
}