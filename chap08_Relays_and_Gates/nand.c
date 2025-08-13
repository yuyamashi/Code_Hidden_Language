#include <stdio.h>

// NAND Gate
int nand_gate(int a, int b) {
    return !(a && b);
}

int main() {
    int switch1 = 0, switch2 = 1;

    int bulb = nand_gate(switch1, switch2);

    printf("Gate (NAND): Bulb is %s\n", bulb ? "ON" : "OFF");
    return 0;
}