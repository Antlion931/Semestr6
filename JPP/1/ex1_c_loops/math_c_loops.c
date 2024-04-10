/**
 * @file math_c_loops.c
 * @brief C implementation of math functions using loops.
 */

#include <stdint.h>
#include "math_c_loops.h"

/**
 * @brief Calculate the factorial of a given integer using a loop.
 * @param n The integer whose factorial is to be calculated.
 * @return The factorial of the given integer. Or 0 if the given integer is bigger then 20.
 *
 * Example usage:
 * @code{.c}
 * #include "math_c_loops.h"
 * #include <stdio.h>
 *
 * int main() {
 *     int64_t result = l_factorial(5); // Calculate factorial of 5
 *     printf("Factorial of 5 is: %ld\n", result); // Output: 120
 *     return 0;
 * }
 * @endcode
 */
uint64_t l_factorial(uint64_t n) {
    if (n > 20) {
        return 0;
    }

    uint64_t result = 1;

    for (uint64_t i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

