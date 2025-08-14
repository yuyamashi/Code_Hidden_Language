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

// Function to calculate sum and carry for first half adder
void half_block1(int input1, int input2, int *sum1, int *carry1, int *carry2) {
    *sum1 = and_gate(nand_gate(input1, input2), or_gate(input1, input2));
    *carry1 = or_gate(input1, input2);
    *carry2 = and_gate(input1, input2);
}

// Function to calculate sum and carry for second half adder
void half_block2(int input1, int input2, int input3, int *sum, int *carry3) {
    *sum = and_gate(nand_gate(input1, input2), or_gate(input1, input2));
    *carry3 = and_gate(input2, input3);
}

// Function to calculate sum and carry for full adder
void full_block(int input1, int input2, int carry_in, int *sum, int *carry) {
    int sum1, carry1, carry2, carry3;
    half_block1(input1, input2, &sum1, &carry1, &carry2);
    half_block2(sum1, carry_in, carry1, sum, &carry3);
    *carry = or_gate(carry2, carry3);
}

int main() {
    int a = 0, b = 1, carry_in = 1;
    
    int sum, carry;
    full_block(a, b, carry_in, &sum, &carry);

    printf("Sum: %d\n", sum);
    printf("Carry Out: %d\n", carry);

    return 0;
}