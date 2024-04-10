/**
 * @file math_c_recursion.c
 * @brief C implementation of math functions using loops.
 */

#include <stdint.h>
#include "math_c_recursion.h"

uint64_t factorial_recursive(uint64_t n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial_recursive(n - 1);
}

/**
 * @brief Calculate the factorial of a given integer using a recursion.
 * @param n The integer whose factorial is to be calculated.
 * @return The factorial of the given integer. Or 0 if the given integer is bigger then 20.
 *
 * Example usage:
 * @code{.c}
 * #include "math_c_recursion.h"
 * #include <stdio.h>
 *
 * int main() {
 *     int64_t result = r_factorial(5); // Calculate factorial of 5
 *     printf("Factorial of 5 is: %ld\n", result); // Output: 120
 *     return 0;
 * }
 * @endcode
 */
uint64_t r_factorial(uint64_t n) {
    if (n > 20) {
        return 0;
    }

    return factorial_recursive(n);
}


