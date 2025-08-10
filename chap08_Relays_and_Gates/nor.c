#include <stdio.h>

// NOR Gate: OR followed by NOT
int nor_gate(int a, int b) {
    return !(a || b);
}

int main() {
    int switch1 = 0, switch2 = 0;

    int bulb = nor_gate(switch1, switch2);
    
    printf("Gate (NOR): Bulb is %s\n", bulb ? "ON" : "OFF");
    return 0;
}