//! # rust_recursion
//!
//! `rust_recursion` is a Rust library for mathematical operations using recursion.
//! 
//! This module provides functions to calculate factorial, gcd, and solve linear diophantine equations recursively.

/// Calculate the factorial of a given integer using recursion.
///
/// # Arguments
///
/// * `n` - The integer whose factorial is to be calculated.
///
/// # Returns
///
/// The factorial of the given integer. Or 0 if the given integer is bigger than 20.
///
/// # Example
///
/// ```
/// use rust_recursion::r_factorial;
///
/// let result = r_factorial(5);
/// assert_eq!(result, 120); // Output: 120
/// ```
#[no_mangle]
pub extern "C" fn r_factorial(n: u64) -> u64 {
    if n > 20 {
        return 0;
    }

    factorial_recursive(n)
}

fn factorial_recursive(n: u64) -> u64 {
    if n == 0 {
        return 1;
    }

    n * factorial_recursive(n - 1)
}

/// Calculate the gcd of numbers a and b using recursion.
///
/// # Arguments
///
/// * `a` - The first number.
/// * `b` - The second number.
///
/// # Returns
///
/// The greatest common divisor of a and b.
///
/// # Example
///
/// ```
/// use rust_recursion::r_gcd;
///
/// let result = r_gcd(12, 15);
/// assert_eq!(result, 3); // Output: 3
/// ```
#[no_mangle]
pub extern "C" fn r_gcd(a: u64, b: u64) -> u64 {
    if b == 0 {
        return a;
    }

    r_gcd(b, a % b)
}

/// Calculate the solution of a linear diophantine equation of form ax + by = c using recursion.
///
/// # Arguments
///
/// * `a` - The coefficient of x.
/// * `b` - The coefficient of y.
/// * `c` - The constant term.
///
/// # Returns
///
/// The solution of the linear diophantine equation.
///
/// # Example
///
/// ```
/// use rust_recursion::r_solve_linear_diophantine;
///
/// let result = r_solve_linear_diophantine(12, 15, 3);
/// if result.is_solution {
///     assert_eq!(result.x, -1);
///     assert_eq!(result.y, 1);
///     println!("Solution of 12x + 15y = 3 is: x = {}, y = {}", result.x, result.y); // Output: x = -1, y = 1
/// } else {
///     println!("No solution exists.");
/// }
/// ```
#[no_mangle]
pub extern "C" fn r_solve_linear_diophantine(a: i64, b: i64, c: i64) -> RLinearSolution {
    if a == 0 && b == 0 {
        return RLinearSolution { is_solution: c == 0, x: 0, y: 0 };
    }

    let result = extended_gcd(a, b);

    if c % result.gcd != 0 {
        return RLinearSolution { is_solution: false, x: 0, y: 0 };
    }

    RLinearSolution { is_solution: true, x: result.x * (c / result.gcd), y: result.y * (c / result.gcd) }
}

#[repr(C)]
/// Represents the result of a linear diophantine equation solution.
pub struct RLinearSolution {
    /// Indicates if a solution exists.
    pub is_solution: bool,
    /// The solution for x.
    pub x: i64,
    /// The solution for y.
    pub y: i64,
}

fn extended_gcd(a: i64, b: i64) -> ExtendedGcdResult {
    if b == 0 {
        return ExtendedGcdResult { gcd: a, x: 1, y: 0 };
    }

    let result = extended_gcd(b, a % b);
    ExtendedGcdResult { gcd: result.gcd, x: result.y, y: result.x - (a / b) * result.y }
}

struct ExtendedGcdResult {
    pub gcd: i64,
    pub x: i64,
    pub y: i64,
}

