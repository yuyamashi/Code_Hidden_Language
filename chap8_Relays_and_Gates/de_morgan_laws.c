#include <stdio.h>

// De Morgan's First Law: NOT(A AND B) = NOT(A) OR NOT(B)
int demorgan_first(int a, int b) {
    int left_side = !(a && b);        // NOT(A AND B)
    int right_side = !a || !b;        // NOT(A) OR NOT(B)
    return left_side == right_side;   // Should always return 1 (true)
}

// De Morgan's Second Law: NOT(A OR B) = NOT(A) AND NOT(B)
int demorgan_second(int a, int b) {
    int left_side = !(a || b);        // NOT(A OR B)
    int right_side = !a && !b;        // NOT(A) AND NOT(B)
    return left_side == right_side;   // Should always return 1 (true)
}

int main() {
    printf("Testing De Morgan's Laws:\n");
    
    // Test all possible combinations (0,0), (0,1), (1,0), (1,1)
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("A=%d, B=%d: ", a, b);
            printf("Law1=%s, Law2=%s\n", 
                   demorgan_first(a, b) ? "TRUE" : "FALSE",
                   demorgan_second(a, b) ? "TRUE" : "FALSE");
        }
    }
    return 0;
}