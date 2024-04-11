/**
 * @file math_c_loops.c
 * @brief C implementation of math functions using loops.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
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

/**
 * @brief Calculate the greatest common divisor of two given integers using a loop.
 * @param a The first integer.
 * @param b The second integer.
 * @return The greatest common divisor of the two given integers.
 *
 * Example usage:
 * @code{.c}
 * #include "math_c_loops.h"
 * #include <stdio.h>
 *
 * int main() {
 *     uint64_t result = l_gcd(12, 18); // Calculate GCD of 12 and 18
 *     printf("GCD of 12 and 18 is: %ld\n", result); // Output: 6
 *     return 0;
 * }
 * @endcode
 */
uint64_t l_gcd(uint64_t a, uint64_t b) {
    if (a > b) {
        uint64_t temp = a;
        a = b;
        b = temp;
    }

    while (a != 0) {
        uint64_t temp = a;
        a = b % a;
        b = temp;
    }

    return b;
}

/**
 * @brief Solve a linear diophantine equation of form ax + by = c using a loop.
 * @param a The coefficient of x.
 * @param b The coefficient of y.
 * @param c The constant value.
 * @return A structure containing the solution of the linear diophantine equation.
 *
 * Example usage:
 * @code{.c}
 * #include "math_c_loops.h"
 * #include <stdio.h>
 *
 * int main() {
 *  L_LinearSolution solution = l_solve_linear_diophantine(3, 5, 12); // Solve 3x + 5y = 12
 *    if (solution.is_solution) {
 *      printf("Solution: x = %ld, y = %ld\n", solution.x, solution.y);
 *      // Output: Solution: x = 2, y = 2
 *      return 0;
 *    }
 *    printf("No solution found.\n");
 *    return 1;
 *  }
 *  @endcode
 */
struct L_LinearSolution l_solve_linear_diophantine(int64_t a, int64_t b, int64_t c) {
    int64_t new_x = 1;
    int64_t old_x = 0;

    int64_t new_y = 0;
    int64_t old_y = 1;

    if (a > b) {
        uint64_t temp = a;
        a = b;
        b = temp;

        new_x = 0;
        old_x = 1;

        new_y = 1;
        old_y = 0;
    }

    while (a != 0) {
        int64_t quotient = b / a;
        int64_t remainder = b % a;

        int64_t temp = new_x;
        new_x = old_x - quotient * new_x;
        old_x = temp;

        temp = new_y;
        new_y = old_y - quotient * new_y;
        old_y = temp;

        b = a;
        a = remainder;
    }

    if (b != 0 && c % b == 0) {
        int64_t k = c / b;

        old_x *= k;
        old_y *= k;

        struct L_LinearSolution result = {true, old_x, old_y};
        return result;
    } else {
        struct L_LinearSolution result = {false, 0, 0};
        return result;
    }
}
