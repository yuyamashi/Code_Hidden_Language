#include <stdio.h>

// AND Gate: Output is 1 only if both inputs are 1
int and_gate(int a, int b) {
    return a && b;
}

int main() {
    int switch1 = 1; // 1 = ON, 0 = OFF
    int switch2 = 1;

    int bulb = and_gate(switch1, switch2);

    printf("Gate (AND): Bulb is %s\n", bulb ? "ON" : "OFF");
    return 0;
}