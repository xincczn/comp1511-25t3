How your program looks like in memory.
It is divided into 3 segments:
- Text: Where all of your code is located like `main()`, etc. 
- Heap: Where all memory allocated with `malloc()` is stored.
- Stack: Where all memory allocated from your functions and themselves are stored.
```c
[TEXT]
    int main() {
        int a = 10;
        char c = 'x';

        int *result = add_one(a);
        printf("%d\n", *result);
    }

    int *add_one(int number) {
        int *total = malloc(sizeof(int));
        *total = number + 1;

        return total;  // current executing this line of code
    }
[HEAP]
0x10000000: 11


// The STACK and the HEAP grow in size towards each other
// But they should never overlap


0xFFFFF000: add_one():
            - total: 0x10000000

0xFFFFFF00: main():
            - a: 10
            - b: 'x'
[STACK]
```

Stack Allocation Advantages:
- **Speed**: Faster than heap allocation due to simple pointer manipulation and no complex memory management.
- **Deterministic Behavior**: Memory automatically de-allocated when out of scope, ensuring predictable memory management.

Stack Allocation Disadvantages:
- **Limited Size**: Bound by OS, risking stack overflow errors with excessive memory allocation.
- **Static Allocation**: Size of stack-allocated variables must be known at compile-time, hindering dynamic or large data structure allocation.

Heap Allocation Advantages:
- **Dynamic Memory**: Allows dynamic memory allocation at runtime for changing memory requirements.
- **Flexible Management**: Enables resizable data structures through dynamic allocation and deallocation.
- **Large Memory Space**: Offers more memory space compared to the stack, accommodating large data structures.

Heap Allocation Disadvantages:
- **Manual Memory Management**: Requires explicit de-allocation to prevent leaks, leading to issues like fragmentation or dangling pointers.
- **Slower Performance**: Involves more overhead due to memory management operations, impacting performance.
- **Fragmentation**: Frequent allocation/de-allocation may cause memory fragmentation, reducing overall efficiency.