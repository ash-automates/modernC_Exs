#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Function prototypes
size_t upper_bound(void);
void something(size_t i);
void something_else(size_t i);

int main(void) {
    // Loop 1: Counts down from 10 to 1, stops when i becomes 0
    // Key takeaway: Using the value itself as condition is a common C idiom
    for (size_t i = 10; i; --i) {
        something(i);
    }
    
    // Loop 2: Standard counting up loop with boundary from a function
    for (size_t i = 0, stop = upper_bound(); i < stop; ++i) {
        something_else(i);
    }
    
    // Loop 3: Demonstrates unsigned integer underflow
    // Key takeaway: When size_t (unsigned) reaches 0 and decrements,
    // it wraps to maximum value, making i <= 9 false and terminating the loop
    for (size_t i = 9; i <= 9; --i) {
        something_else(i);
    }
    
    return EXIT_SUCCESS;
}

// Simple function implementations
size_t upper_bound(void) { return 31; }
void something(size_t i) { printf("something: %zu\n", i); }
void something_else(size_t i) { printf("something_else: %zu\n", i); }