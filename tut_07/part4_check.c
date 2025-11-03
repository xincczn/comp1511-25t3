// Xing He, z5413977, 04/11/2025
// Part 4.4: Check for Command Line Arguments (Your Turn!)

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("No command-line arguments provided.\n");
    } else {
        printf("Number of arguments: %d\n", argc - 1);
    }

    return 0;
}
