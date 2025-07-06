#include <stdio.h>

// AND Gate: Output is 1 only if both inputs are 1
int and_gate(int a, int b) {
    return a && b;
}

// OR Gate: Output is 1 if either input is 1
int or_gate(int a, int b) {
    return a || b;
}

// NAND Gate: AND followed by NOT
int nand_gate(int a, int b) {
    return !(a && b);
}

// NOR Gate: OR followed by NOT
int nor_gate(int a, int b) {
    return !(a || b);
}

void print_truth_table() {
    printf("A B | AND OR NAND NOR\n");
    printf("----|----------------\n");
    
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("%d %d |  %d   %d   %d    %d\n", 
                   a, b,
                   and_gate(a, b),
                   or_gate(a, b),
                   nand_gate(a, b),
                   nor_gate(a, b));
        }
    }
}

int main() {
    print_truth_table();
    return 0;
}