#include <stdio.h>

// NAND Gate: AND followed by NOT
int nand_gate(int a, int b) {
    return !(a && b);
}

int main() {
    int switch1 = 0; // 1 = ON, 0 = OFF
    int switch2 = 1;

    int bulb = nand_gate(switch1, switch2);

    printf("Gate (NAND): Bulb is %s\n", bulb ? "ON" : "OFF");
    return 0;
}