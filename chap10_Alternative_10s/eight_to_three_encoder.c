#include <stdio.h>

int main() {
    int input0 = 0;
    int input1 = 0;
    int input2 = 0;
    int input3 = 0;
    int input4 = 0;
    int input5 = 0;
    int input6 = 0;
    int input7 = 1;

    // Calculate each output using OR gates
    int output0 = input4 || input5 || input6 || input7;
    int output1 = input2 || input3 || input6 || input7;
    int output2 = input1 || input3 || input5 || input7;

    // Display results
    printf("Encoder Outputs:\n");
    printf("Output 0: %s\n", output0 ? "ON" : "OFF");
    printf("Output 1: %s\n", output1 ? "ON" : "OFF");
    printf("Output 2: %s\n", output2 ? "ON" : "OFF");

    return 0;
}