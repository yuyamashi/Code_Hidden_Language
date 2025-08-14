#include <stdio.h>

// And gate
int series_and(int switch1, int switch2) {
    return switch1 && switch2;
}

int main() {
    int switch1 = 1, switch2 = 1;

    int bulb = series_and(switch1, switch2);

    printf("Series (AND): Bulb is %s\n", bulb ? "ON" : "OFF");
    return 0;
}