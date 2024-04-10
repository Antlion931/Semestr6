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
