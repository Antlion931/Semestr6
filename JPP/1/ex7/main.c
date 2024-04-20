#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct L_Linear_Solution {
    bool Is_Solution;
    int64_t x;
    int64_t y;
};

extern uint64_t l_factorial(uint64_t n);
extern uint64_t l_gcd(uint64_t a, uint64_t b);
extern struct L_Linear_Solution l_solve_linear_diophantine(int64_t a, int64_t b, int64_t c);

struct R_Linear_Solution {
    bool Is_Solution;
    int64_t x;
    int64_t y;
};

extern uint64_t r_factorial(uint64_t n);
extern uint64_t r_gcd(uint64_t a, uint64_t b);
extern struct R_Linear_Solution r_solve_linear_diophantine(int64_t a, int64_t b, int64_t c);
 
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

    {
        struct L_Linear_Solution solution = l_solve_linear_diophantine(46, 240, 8);
        printf("For 46x + 240y = 8: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);

        solution = l_solve_linear_diophantine(240, 46, 8);
        printf("For 240x + 46y = 8: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);

        solution = l_solve_linear_diophantine(240, 46, 7);
        printf("For 240x + 46y = 7: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);

        solution = l_solve_linear_diophantine(0, 0, 5);
        printf("For 0x + 0y = 5: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);

        solution = l_solve_linear_diophantine(0, 0, 0);
        printf("For 0x + 0y = 0: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);
    }
    printf("\nRecursion:\n\n");

    for (uint64_t i = 0; i < 25; i += 4) {
        printf("factorial of %ld is: %ld\n", i, r_factorial(i));
    }

    printf("\n");

    printf("gcd(10, 5) = %ld\n", r_gcd(10, 5));
    printf("gcd(14, 21) = %ld\n", r_gcd(14, 21));
    printf("gcd(21, 14) = %ld\n", r_gcd(21, 14));

    printf("\n");

    {
        struct R_Linear_Solution solution = r_solve_linear_diophantine(46, 240, 8);
        printf("For 46x + 240y = 8: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);

        solution = r_solve_linear_diophantine(240, 46, 8);
        printf("For 240x + 46y = 8: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);

        solution = r_solve_linear_diophantine(240, 46, 7);
        printf("For 240x + 46y = 7: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);

        solution = r_solve_linear_diophantine(0, 0, 5);
        printf("For 0x + 0y = 5: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);

        solution = r_solve_linear_diophantine(0, 0, 0);
        printf("For 0x + 0y = 0: is_solution = %s, x = %ld, y = %ld\n", solution.Is_Solution ? "true" : "false", solution.x, solution.y);
    }
    return 0;
}

