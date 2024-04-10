#include "math_c_loops.h"
#include "math_c_recursion.h"
#include <stdint.h>
#include <stdio.h>
 
int main() {
    printf("Loops:\n");

    for (uint64_t i = 0; i < 25; i++) {
        printf("Fibonacci of %ld is: %ld\n", i, l_factorial(i));
    }

    printf("\nRecursion:\n");

    for (uint64_t i = 0; i < 25; i++) {
        printf("Fibonacci of %ld is: %ld\n", i, r_factorial(i));
    }

    return 0;
}
