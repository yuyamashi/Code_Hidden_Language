// OR Gate: Output is 1 if either input is 1
int or_gate(int a, int b) {
    return a || b;
}

int main() {
    int switch1 = 1; // 1 = ON, 0 = OFF
    int switch2 = 1;

    int bulb = or_gate(switch1, switch2);

    printf("Gate (OR): Bulb is %s\n", bulb ? "ON" : "OFF");
    return 0;
}