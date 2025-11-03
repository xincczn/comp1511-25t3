// Xing He, z5413977, 04/11/2025
// Part 4.2: Count Characters in Command Line Arguments (Your Turn!)

#include <stdio.h>

int main(int argc, char *argv[]) {
    int count = 0;

    // Use a 2d loop since an array of strings is just a 2d array of characters
    for (int i = 1; i < argc; i++) {
        // Inner loop iterates through each character of the string
        for (int j = 0; argv[i][j] != '\0'; j++) {
            count++;
        }
    }

    printf("Total Characters: %d\n", count);

    return 0;
}
