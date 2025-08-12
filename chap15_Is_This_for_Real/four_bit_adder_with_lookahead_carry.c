#include <stdio.h>

// NAND gate
int nand_gate(int input1, int input2) {
    return !(input1 && input2);
}

// AND gate with two inputs
int and_gate(int input1, int input2) {
    return input1 && input2;
}

// AND gate with three inputs
int and_gate3(int input1, int input2, int input3) {
    return input1 && input2 && input3;
}

// AND gate with four inputs
int and_gate4(int input1, int input2, int input3, int input4) {
    return input1 && input2 && input3 && input4;
}

// AND gate with five inputs
int and_gate5(int input1, int input2, int input3, int input4, int input5) {
    return input1 && input2 && input3 && input4 && input5;
}

// OR gate with two inputs
int or_gate(int input1, int input2) {
    return input1 || input2;
}

// OR gate with three inputs
int or_gate3(int input1, int input2, int input3) {
    return input1 || input2 || input3;
}

// OR gate with four inputs
int or_gate4(int input1, int input2, int input3, int input4) {
    return input1 || input2 || input3 || input4;
}

// OR gate with five inputs
int or_gate5(int input1, int input2, int input3, int input4, int input5) {
    return input1 || input2 || input3 || input4 || input5;
}

// Function to calculate sum and carry for first half adder
void first_half_block(int input1, int input2, int *sum1, int *p, int *g) {
    *sum1 = and_gate(nand_gate(input1, input2), or_gate(input1, input2));
    *p = or_gate(input1, input2);
    *g = and_gate(input1, input2);
}

// Function to calculate sum and carry for second half adder
void second_half_block(int sum1, int carry_in, int *sum) {
    *sum = and_gate(nand_gate(sum1, carry_in), or_gate(sum1, carry_in));
}

// Function to calculate carry (Bit 0)
void carry_block0(int carry_in, int p0, int g0, int *carry_out) {
    *carry_out = or_gate(and_gate(carry_in, p0), g0);
}

// Function to calculate carry (Bit 1)
void carry_block1(int carry_in, int p0, int g0, int p1, int g1, int *carry_out) {
    *carry_out = or_gate3(and_gate3(carry_in, p0, p1), and_gate(g0, p1), g1);
}

// Function to calculate carry (Bit 2)
void carry_block2(int carry_in, int p0, int g0, int p1, int g1, int p2, int g2, int *carry_out) {
    *carry_out = or_gate4(and_gate4(carry_in, p0, p1, p2), and_gate3(g0, p1, p2), and_gate(g1, g2), g2);
}

// Function to calculate carry (Bit 3)
void carry_block3(int carry_in, int p0, int g0, int p1, int g1, int p2, int g2, int p3, int g3, int *carry_out) {
    *carry_out = or_gate5(and_gate5(carry_in, p0, p1, p2, p3), and_gate4(g0, p1, p2, p3), and_gate3(g1, g2, g3), and_gate(g2, g3), g3);
}

// Function to calculate sum and carry for full adder (Bit 0)
void full_block0(int input1, int input2, int carry_in, int *sum, int *carry_out, int *p0, int *g0) {
    int sum1;
    first_half_block(input1, input2, &sum1, p0, g0);
    second_half_block(sum1, carry_in, sum);
    carry_block0(carry_in, *p0, *g0, carry_out);
}

// Function to calculate sum and carry for full adder (Bit 1)
void full_block1(int input1, int input2, int carry_in, int p0, int g0, int *sum, int *carry_out, int *p1, int *g1) {
    int sum1;
    first_half_block(input1, input2, &sum1, p1, g1);
    second_half_block(sum1, carry_in, sum);
    carry_block1(carry_in, p0, g0, *p1, *g1, carry_out);
}

// Function to calculate sum and carry for full adder (Bit 2)
void full_block2(int input1, int input2, int carry_in, int p0, int g0, int p1, int g1, int *sum, int *carry_out, int *p2, int *g2) {
    int sum1;
    first_half_block(input1, input2, &sum1, p2, g2);
    second_half_block(sum1, carry_in, sum);
    carry_block2(carry_in, p0, g0, p1, g1, *p2, *g2, carry_out);
}

// Function to calculate sum and carry for full adder (Bit 3)
void full_block3(int input1, int input2, int carry_in, int p0, int g0, int p1, int g1, int p2, int g2, int *sum, int *carry_out, int *p3, int *g3) {
    int sum1;
    first_half_block(input1, input2, &sum1, p3, g3);
    second_half_block(sum1, carry_in, sum);
    carry_block3(carry_in, p0, g0, p1, g1, p2, g2, *p3, *g3, carry_out);
}

// Function to calculate sum and carry for four bit adder
void four_bit_adder(int a[4], int b[4], int carry_in, int sum[4], int *carry_out) {
    int carry = carry_in;
    int p[4], g[4];

    // Bit 0
    full_block0(a[3], b[3], carry, &sum[3], &carry, &p[3], &g[3]);

    // Bit 1
    full_block1(a[2], b[2], carry, p[3], g[3], &sum[2], &carry, &p[2], &g[2]);

    // Bit 2
    full_block2(a[1], b[1], carry, p[3], g[3], p[2], g[2], &sum[1], &carry, &p[1], &g[1]);

    // Bit 3
    full_block3(a[0], b[0], carry, p[3], g[3], p[2], g[2], p[1], g[1], &sum[0], &carry, &p[0], &g[0]);

    *carry_out = carry;
}

// Main function to test the four bit adder
int main() {
    int a[4] = {1, 0, 1, 1};
    int b[4] = {1, 1, 0, 1};
    int carry_in = 0;

    int sum[4], carry_out;
    four_bit_adder(a, b, carry_in, sum, &carry_out);

    printf("Sum: %d", carry_out);
    for (int i = 0; i <= 3; i++) {
        printf("%d", sum[i]);
    }
    printf("\n");

    return 0;
}