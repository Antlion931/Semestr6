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

/**
 * @brief Calculate the gcd of numbers a and b using recursion.
 * @param a,b numbers.
 * @return greatest common divisor of a and b.
 *
 * Example usage:
 * @code{.c}
 * #include "math_c_recursion.h"
 * #include <stdio.h>
 *
 * int main() {
 *    int64_t result = r_gcd(12, 15); // Calculate gcd of 12 and 15
 *    printf("GCD of 12 and 15 is: %ld\n", result); // Output: 3
 *    return 0;
 * }
 * @endcode
 */
uint64_t r_gcd(uint64_t a, uint64_t b) {
    if (b == 0) {
        return a;
    }

    return r_gcd(b, a % b);
}

