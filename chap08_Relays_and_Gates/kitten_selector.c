#include <stdio.h>

int main() {
    // Inputs: 0 = OFF, 1 = ON
    int female = 1;
    int neutered = 0;
    int black = 0;
    int white = 0;
    int tan = 0;

    // Derived signals
    int male = !female;
    int not_white = !white;

    // Logic branches
    int branch1 = white || tan;
    int branch2 = male && branch1;
    int branch3 = female && not_white;
    int branch4 = branch2 || branch3;
    int branch5 = neutered && branch4;

    // Final output
    int bulb = branch5 || black;

    printf("Kitten selector result: %s\n", bulb ? "BULB ON (Selected)" : "BULB OFF (Not selected)");
    return 0;
}