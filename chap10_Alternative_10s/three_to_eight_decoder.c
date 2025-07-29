#include <stdio.h>

int main() {
    int input1 = 1;
    int input2 = 0;
    int input3 = 1;

    // Calculate each bulb state using AND gates
    int bulb0 = !input1 && !input2 && !input3;  // 000
    int bulb1 = !input1 && !input2 && input3;   // 001
    int bulb2 = !input1 && input2 && !input3;   // 010
    int bulb3 = !input1 && input2 && input3;    // 011
    int bulb4 = input1 && !input2 && !input3;   // 100
    int bulb5 = input1 && !input2 && input3;    // 101
    int bulb6 = input1 && input2 && !input3;    // 110
    int bulb7 = input1 && input2 && input3;     // 111
    
    // Display results
    printf("Decoder Outputs:\n");
    printf("Bulb 0: %s\n", bulb0 ? "ON" : "OFF");
    printf("Bulb 1: %s\n", bulb1 ? "ON" : "OFF");
    printf("Bulb 2: %s\n", bulb2 ? "ON" : "OFF");
    printf("Bulb 3: %s\n", bulb3 ? "ON" : "OFF");
    printf("Bulb 4: %s\n", bulb4 ? "ON" : "OFF");
    printf("Bulb 5: %s\n", bulb5 ? "ON" : "OFF");
    printf("Bulb 6: %s\n", bulb6 ? "ON" : "OFF");
    printf("Bulb 7: %s\n", bulb7 ? "ON" : "OFF");

    return 0;
}