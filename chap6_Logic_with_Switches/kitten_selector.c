#include <stdio.h>

// Returns 1 if the kitten matches the selection criteria, 0 otherwise
int kitten_selector(int male, int neutered1, int white, int tan, int female, int neutered2, int not_white, int black) {
    return (male && neutered1 && (white || tan)) ||
           (female && neutered2 && not_white) ||
           (black);
}

int main() {
    // Example kitten attributes
    int male = 1;
    int neutered1 = 1;
    int white = 1;
    int tan = 1;
    int female = 1;
    int neutered2 = 1;
    int not_white = 1;
    int black = 1;

    int matches = kitten_selector(male, neutered1, white, tan, female, neutered2, not_white, black);

    printf("Kitten matches criteria: %s\n", matches ? "YES" : "NO");
    return 0;
}