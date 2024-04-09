/**
 * @file math_c_loop_library.h
 * @brief Header file for math library containing functions implemented using loops.
 */

#ifndef MATH_C_LOOP_LIBRARY_H
#define MATH_C_LOOP_LIBRARY_H

#include <stdint.h>

/**
 * @brief Calculate the factorial of a given integer using a loop.
 * @param n The integer whose factorial is to be calculated.
 * @return The factorial of the given integer.
 * @warning This function may overflow for large values of n.
 *
 * Example usage:
 * @code{.c}
 * #include "math_c_loop_library.h"
 * #include <stdio.h>
 *
 * int main() {
 *     int64_t result = factorial(5); // Calculate factorial of 5
 *     printf("Factorial of 5 is: %ld\n", result); // Output: 120
 *     return 0;
 * }
 * @endcode
 */
uint64_t factorial(uint64_t n) {
    uint64_t result = 1;

    for (uint64_t i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

#endif // MATH_C_LOOP_LIBRARY_H

