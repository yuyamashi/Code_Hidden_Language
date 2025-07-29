#include <stdio.h>

// Returns 1 if both switches are ON (series/AND), 0 otherwise
int series_and(int switch1, int switch2) {
    return switch1 && switch2;
}

int main() {
    int switch1 = 1; // 1 = ON, 0 = OFF
    int switch2 = 1;

    int bulb = series_and(switch1, switch2);

    printf("Series (AND): Bulb is %s\n", bulb ? "ON" : "OFF");
    return 0;
}