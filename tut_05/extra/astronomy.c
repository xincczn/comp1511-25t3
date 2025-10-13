// Space Exploration
// astronomy.c
//
// This program was written by Xing He (z5413977)
// on 13/10/2025
//
// This is a program that maps out stars onto a galaxy.

// =============================================================================
// Libraries
// =============================================================================

#include <stdio.h>

// =============================================================================
// Constants
// =============================================================================

#define SIZE 5

#define PLAYER_POINTS 50
#define NEBULA_POINTS -10
#define DEFAULT_POINTS 0

#define COMMAND_NEBULA 'n'
#define COMMAND_PLANET 'p'
#define COMMAND_QUIT 'q'

// =============================================================================
// Enums
// =============================================================================

enum entity {
    STAR,
    PLANET,
    NEBULA,
    SPACESHIP,
    EMPTY,
};

// =============================================================================
// Structs
// =============================================================================

struct celestial_body {
    enum entity entity;
    int points;
};

// =============================================================================
// Function Prototypes
// =============================================================================

// Provided Functions
void print_map(struct celestial_body galaxy[SIZE][SIZE]);

// =============================================================================
// Main Function
// =============================================================================

int main(void) {
    // type array_name[ROW_SIZE][COL_SIZE];
    struct celestial_body galaxy[SIZE][SIZE];

    initialise_galaxy(galaxy);

    add_celestial_bodies(galaxy);

    add_stars(galaxy);

    print_map(galaxy);

    return 0;
}

// =============================================================================
// Function Definitions
// =============================================================================

void initialise_galaxy(struct celestial_body map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            map[row][col].entity = EMPTY;
            map[row][col].points = DEFAULT_POINTS;
        }
    }  
    
    // parameters
    // modifying an array, does so in place
    // modify a variable, return it to update value

    // update multiple values: using pointers, return a struct
}

// rule of thumb: all functions should do one thing
// Adds celestial bodies from user input onto the map.
void add_celestial_bodies(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("Enter planets and nebulae:\n");
    char input;
    scanf(" %c", &input);
    while (input != COMMAND_QUIT) {
        if (input == COMMAND_PLANET) {
            add_planet(galaxy);
        } else if (input == COMMAND_NEBULA) {
            add_nebula(galaxy);
        }
    }
}

// Adds a planet onto the map. (Does not error check position)
void add_planet(struct celestial_body galaxy[SIZE][SIZE]) {
    // p [row] [col] [points]
    int planet_row;
    int planet_col;
    int planet_points;
    scanf(" %d %d %d", &planet_row, &planet_col, &planet_points);

    galaxy[planet_row][planet_col].entity = PLANETS;
    galaxy[planet_row][planet_col].points = planet_points;
}

// Adds a nebula onto the map. (Does not error check position)
void add_nebula(struct celestial_body galaxy[SIZE][SIZE]) {
    // n [row] [col]
    int nebula_row;
    int nebula_col;
    scanf(" %d %d %d", &nebula_row, &nebula_col);

    galaxy[nebula_row][nebula_col].entity = PLANETS;
    galaxy[nebula_row][nebula_col].points = NEBULA_POINTS;
}

// Adds the player onto the map. Checks position scanned is valid.
void add_player(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("Enter the starting position of the player: ");
    int player_row;
    int player_col;
    scanf(" %d %d", &player_row, &player_col);

    while (
        check_invalid_position(player_row, player_col)
        || is_occupied(player_row, player_col, galaxy)
    ) {
        printf("Invalid starting position!\n");
        printf("Re-enter starting position: ");
        scanf(" %d %d", &player_row, &player_col);
    }

    // Tip: assumptions: safely assume at this line onwards that player_row and col are valid positions
    galaxy[player_row][player_col].entity = SPACESHIP;
    galaxy[player_row][player_col].points = PLAYER_POINTS;
}

// Check if invalid position
int check_invalid_position(int row, int col) {
    return row < 0 || row >= SIZE
           || col < 0 || col >= SIZE;
}

// Check if position is occupied (doesn't validate position itself)
int is_occupied(
    int row, 
    int col,`
    struct celestial_body galaxy[SIZE][SIZE]
) {
    return board[row][col].entity != EMPTY;
}

// Add stars from user input until Ctrl-D is pressed
void add_stars(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("Enter the position and points of the star(s):\n");
    // [row] [col] [points]
    // stopping: Ctrl-D is pressed
    // condtion: Ctrl-D is not pressed

    int star_row;
    int star_col;
    int star_points;
    while (scanf(" %d %d %d", &star_row, &star_col, &star_points) == 3) {
        if (!check_invalid_position(star_row, star_col)) {
            galaxy[star_row][star_col].entity = STAR;
            galaxy[star_row][star_col].points = star_points;
        }
    }
}

// =============================================================================
// Provided Function Definitions
// =============================================================================

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
