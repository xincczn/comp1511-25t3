// Xing He, z5413977, 04/11/2025 
// Part 2: Pointers

#include <stdio.h>

struct box {
    int x;
    int y;
};

int main(void) {

    // <type> <variable_name>;

    // <variable_name> = <value>;
    // <variable_name> /= 2;

    int number = 10;
    char letter = 'a';
    double pi = 3.141592;

    int x = 10;
    int y = x;

    // structs hold multiple values of different types
    // <struct type> <struct_name>;
    // <struct_name>.<field_name> = <value>;

    // .  struct operator (for accessing a field)

    struct box box;
    box.x = 10;
    box.y = box.x;

    // array holds multiple values of the same type
    // <type> <array_name>[<size>];

    int numbers;

    // <array_name>[<index>] = <value>;

    int num_1 = 10;
    int num_2 = num_1;

    numbers[0] = 10;
    numbers[1] = numbers[0];

    // []  array operator (for accessing a particular element)


    // pointers hold a memory address of another variable
    // <type> *<pointer_name>;

    // *  pointer operator (dereference a pointer to become the variable its pointing to)
    

    // 0-9a-f
    
    // decimal: base 10
    // memory address -> hexadecimal number: base 16
    // 0x001f

    int num = 10;
    int *ptr;
    
    // &<variable> (retrieve the memory address of that variable)
    ptr = &num;

    // *  pointer operator (dereferencing, let the pointer be the variable its pointing to)

    *ptr *= 10;  // num = 5;
    printf("%d\n", num);

    // Dereference a pointer
    // 1. look at the variable at the address
    // 2. become that variable
    // 3. dp whatever
  
    // Note: arrays are pointers
    // hence the similar behaviour
    //

    return 0;
}