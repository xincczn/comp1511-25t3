// Space Exploration
// part1_galaxy.c
//
// This program was written by Xing He (z5413977)
// on 01/07/2025
//
// This program is a simple game that allows the user to build a galaxy. 
// The user can place stars, planets, and nebulae in the galaxy.

#include <stdio.h>

#define SIZE 5
#define NEBULA_POINTS -10
#define INITIAL_POINTS 0

#define COMMAND_QUIT 'q'  // although this can be in an enum definition, 
#define COMMAND_PLANET 'p' // its values are ascii which makes it tricky and not worth it
#define COMMAND_NEBULA 'n'

#define TRUE 1
#define FALSE 0

enum entity {
    STAR,       // 0
    PLANET,     // 1
    NEBULA,     // 2
    SPACESHIP,  // 3
    EMPTY,      // 4
};

struct celestial_body {
    enum entity entity;
    int points;
};

void print_map(struct celestial_body galaxy[SIZE][SIZE]);

int main(void) {  // style: functions should be less 50 lines
    struct celestial_body galaxy[SIZE][SIZE];

    // Problem: we need to go through *each* element of the 2d array, 
    //          set each element to have a default value
    //          type: struct celestial body: entity, points


    // FUNCTION: Rule 1: all functions should have one and only one purpose/functionality

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // inner loop: row, col => coord of a given element

            // Problem: how to access an element struct of an array
            // 1. get the element
            // 2. get the field
            galaxy[row][col].entity = EMPTY;
            galaxy[row][col].points = INITIAL_POINTS;  // style: if the value has meaning, #define
        }
    }

    printf("Enter planets and nebulae:\n");
    // Problem:  take input for planets and nebula until q is pressed.
    //  input: scanf()
    //  until: loop
    // stopping condition: input == 'q'
    // condition to continue: input != 'q'
    
    char command;
    scanf(" %c", &command);  // 1. initialising the iterator
    while (command != COMMAND_QUIT) {  // 2. compare the iterator in the condition
        if (command == COMMAND_PLANET) {
            int planet_row;  // style: verbose variable names
            int planet_col;  // style: declare variables as close to as you first use them
            int planet_points;
            scanf(" %d %d %d", &planet_row, &planet_col, &planet_points);
        
            galaxy[planet_row][planet_col].entity = PLANET;
            galaxy[planet_row][planet_col].points = planet_points;
        } else if (command == COMMAND_NEBULA) {  // style: ?
            int nebula_row;  // style: verbose variable names
            int nebula_col;  // style: declare variables as close to as you first use them
            scanf(" %d %d", &nebula_row, &nebula_col);
        
            galaxy[nebula_row][nebula_col].entity = NEBULA;
            galaxy[nebula_row][nebula_col].points = NEBULA_POINTS;
        }

        scanf(" %c", &command); // 3. stepping the iterator (update)
    }

    printf("Enter the starting position of the player: ");
    // problem: re-scan the position of the player, repeating until a valid position is scanned in.
    int player_row;
    int player_col;
    scanf(" %d %d", &player_row, &player_col);
    

    // logic: while loop's condition simply checks if the value is a zero (false) or non-zero (true)
    while (
        player_row < 0 || player_row >= SIZE ||     // style: less than 80 lines liit
        player_col < 0 || player_col >= SIZE ||
        galaxy[row][col].entity != EMPTY
    ) {
        printf("Invalid starting position!\n");
        printf("Re-enter the starting position of the player: ");
        scanf(" %d %d", &player_row, &player_col);
    }
    // logic: if we reach this line, then the player_row and player_col must be valid
    galaxy[player_row][player_col].entity = SPACESHIP;
 
    printf("Enter the position and points of the star(s):\n");
    // until Ctrl-D is pressed

    int star_row;
    int star_col;
    int star_points;
    while (scanf(" %d %d %d", &star_row, &star_col, &star_points) == 3) {
        if (!is_out_of_bounds(star_row, star_col)) {
            galaxy[star_row][star_col].entity = STAR;
            galaxy[star_row][star_col].points = star_points;
        }
    }

    print_map(galaxy);
    

    return 0;
}

// Function prints the map of the galaxy
// 
// Parameters:
// - galaxy: the 2D array representing the galaxy
//
// returns: nothing
void print_map(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("\n---------------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|");
            if (galaxy[i][j].entity == SPACESHIP) {
                printf(" X ");
            } else if (galaxy[i][j].entity == EMPTY) {
                printf("   ");
            } else if (galaxy[i][j].entity == STAR) {
                printf(" * ");
            } else if (galaxy[i][j].entity == PLANET) {
                printf(" o ");
            } else if (galaxy[i][j].entity == NEBULA) {
                printf(" # ");
            }
        }
        printf("|\n");
        printf("---------------------\n");
    }
}

// Example function decomposition
// NOTE: Arrays cannot be return
// NOTE: Arrays are mutable (can be modified with its value passed into function)
void initialise_galaxy(struct celestial_body galaxy[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // inner loop: row, col => coord of a given element

            // Problem: how to access an element struct of an array
            // 1. get the element
            // 2. get the field
            galaxy[row][col].entity = EMPTY;
            galaxy[row][col].points = INITIAL_POINTS;  // style: if the value has meaning, #define
        }
    }

}

void insert_distinct_celestial_bodies(
    struct celestial_body galaxy[SIZE][SIZE]
) {
    printf("Enter planets and nebulae:\n");
    // Problem:  take input for planets and nebula until q is pressed.
    //  input: scanf()
    //  until: loop
    // stopping condition: input == 'q'
    // condition to continue: input != 'q'
    
    char command;
    scanf(" %c", &command);  // 1. initialising the iterator
    while (command != COMMAND_QUIT) {  // 2. compare the iterator in the condition
        if (command == COMMAND_PLANET) {
            insert_planet(galaxy);
        } else if (command == COMMAND_NEBULA) {  // style: ?
            insert_nebula(galaxy);
        }

        scanf(" %c", &command); // 3. stepping the iterator (update)
    }
}

void insert_planet(struct celestial_body galaxy[SIZE][SIZE]) {
    int planet_row;  // style: verbose variable names
    int planet_col;  // style: declare variables as close to as you first use them
    int planet_points;
    scanf(" %d %d %d", &planet_row, &planet_col, &planet_points);

    galaxy[planet_row][planet_col].entity = PLANET;
    galaxy[planet_row][planet_col].points = planet_points;
}

void insert_nebula(struct celestial_body galaxy[SIZE][SIZE]) {
    int nebula_row;  // style: verbose variable names
    int nebula_col;  // style: declare variables as close to as you first use them
    scanf(" %d %d", &nebula_row, &nebula_col);

    galaxy[nebula_row][nebula_col].entity = NEBULA;
    galaxy[nebula_row][nebula_col].points = NEBULA_POINTS;
}

void insert_player(struct celestial_body galaxy[SIZE][SIZE]) {
    int player_row;
    int player_col;
    scanf(" %d %d", &player_row, &player_col);
    

    // logic: while loop's condition simply checks if the value is a zero (false) or non-zero (true)
    while (
        is_out_of_bounds(player_row, player_col) ||
        is_occupied(galaxy, player_row, player_col)
    ) {
        printf("Invalid starting position!\n");
        printf("Re-enter the starting position of the player: ");
        scanf(" %d %d", &player_row, &player_col);
    }
    // logic: if we reach this line, then the player_row and player_col must be valid
    galaxy[player_row][player_col].entity = SPACESHIP;
}

int is_out_of_bounds(int row, int col) {
    return row < 0 || row >= SIZE ||     // style: less than 80 lines liit
           col < 0 || col >= SIZE;
}

int is_occupied(struct celestial_body galaxy[SIZE][SIZE], int row, int col) {
    return galaxy[row][col].entity != EMPTY;
}

void insert_stars(struct celestial_body galaxy[SIZE][SIZE]) {
    int star_row;
    int star_col;
    int star_points;
    while (scanf(" %d %d %d", &star_row, &star_col, &star_points) == 3) {
        if (!is_out_of_bounds(star_row, star_col)) {
            galaxy[star_row][star_col].entity = STAR;
            galaxy[star_row][star_col].points = star_points;
        }
    }
}