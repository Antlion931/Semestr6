#ifndef MATH_C_RECURSION_H
#define MATH_C_RECURSION_H 

#include <stdint.h>
#include <stdbool.h>

uint64_t r_factorial(uint64_t n);

uint64_t r_gcd(uint64_t a, uint64_t b);

/**
 * @brief Structure to hold the solution of a linear diophantine equation of form ax + by = c.
 * @struct L_LinearSolution
 * @var L_LinearSolution::is_solution
 * Boolean value indicating if a solution exists.
 * @var L_LinearSolution::x
 * The value of x in the solution.
 * @var L_LinearSolution::y
 * The value of y in the solution.
 */

struct R_LinearSolution {
    bool is_solution;
    int64_t x;
    int64_t y; 
};

struct R_LinearSolution r_solve_linear_diophantine(int64_t a, int64_t b, int64_t c);

#endif /* MATH_C_RECURSION_H */

