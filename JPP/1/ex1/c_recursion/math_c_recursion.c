/**
 * @file math_c_recursion.c
 * @brief C implementation of math functions using loops.
 */

#include <stdint.h>
#include "math_c_recursion.h"
#include <stdbool.h>

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

struct extended_gcd_result {
    int64_t gcd;
    int64_t x;
    int64_t y;
};

struct extended_gcd_result extended_gcd(int64_t a, int64_t b) {
    if (b == 0) {
        return (struct extended_gcd_result){a, 1, 0};
    }

    struct extended_gcd_result result = extended_gcd(b, a % b);
    return (struct extended_gcd_result){result.gcd, result.y, result.x - (a / b) * result.y};
}

/**
 * @brief Calculate the solution of a linear diophantine equation of form ax + by = c using recursion.
 * @param a,b,c numbers.
 * @return The solution of the linear diophantine equation.
 *
 * Example usage:
 * @code{.c}
 * #include "math_c_recursion.h"
 * #include <stdio.h>
 *
 * int main() {
 *    struct R_LinearSolution result = r_solve_linear_diophantine(12, 15, 3); // Calculate solution of 12x + 15y = 3
 *    if (result.is_solution) {
 *        printf("Solution of 12x + 15y = 3 is: x = %ld, y = %ld\n", result.x, result.y); 
 *        // Output: x = -1, y = 1
 *    } else {
 *        printf("No solution exists.\n");
 *    }
 *    return 0;
 * }
 * @endcode
 */
struct R_LinearSolution r_solve_linear_diophantine(int64_t a, int64_t b, int64_t c) {
    if (a == 0 && b == 0) {
        return (struct R_LinearSolution){c == 0, 0, 0};
    }

    struct extended_gcd_result result = extended_gcd(a, b);

    if (c % result.gcd != 0) {
        return (struct R_LinearSolution){false, 0, 0};
    }

    return (struct R_LinearSolution){true, result.x * (c / result.gcd), result.y * (c / result.gcd)};
}

