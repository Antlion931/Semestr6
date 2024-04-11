#include "math_c_loops.h"
#include "math_c_recursion.h"
#include <stdint.h>
#include <stdio.h>
 
int main() {
    printf("Loops:\n\n");

    for (uint64_t i = 0; i < 25; i += 4) {
        printf("Factorial of %ld is: %ld\n", i, l_factorial(i));
    }

    printf("\n");

    printf("gcd(10, 5) = %ld\n", l_gcd(10, 5));
    printf("gcd(14, 21) = %ld\n", l_gcd(14, 21));
    printf("gcd(21, 14) = %ld\n", l_gcd(21, 14));

    printf("\n");

    struct L_LinearSolution solution = l_solve_linear_diophantine(46, 240, 8);
    printf("For 46x + 240y = 8: is_solution = %s, x = %ld, y = %ld\n", solution.is_solution ? "true" : "false", solution.x, solution.y);

    solution = l_solve_linear_diophantine(240, 46, 8);
    printf("For 240x + 46y = 8: is_solution = %s, x = %ld, y = %ld\n", solution.is_solution ? "true" : "false", solution.x, solution.y);

    solution = l_solve_linear_diophantine(240, 46, 7);
    printf("For 240x + 46y = 7: is_solution = %s, x = %ld, y = %ld\n", solution.is_solution ? "true" : "false", solution.x, solution.y);

    printf("\nRecursion:\n\n");

    for (uint64_t i = 0; i < 25; i += 4) {
        printf("Factorial of %ld is: %ld\n", i, r_factorial(i));
    }

    printf("\n");

    printf("gcd(10, 5) = %ld\n", r_gcd(10, 5));
    printf("gcd(14, 21) = %ld\n", r_gcd(14, 21));
    printf("gcd(21, 14) = %ld\n", r_gcd(21, 14));

    return 0;
}
