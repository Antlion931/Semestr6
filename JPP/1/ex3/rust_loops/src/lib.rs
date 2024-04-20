//! # rust_loops
//!
//! `rust_loops` is a Rust library for mathematical operations using loops.
//! 
//! This module provides functions to calculate factorial, gcd, and solve linear diophantine equations using loops.

/// Calculate the factorial of a given integer using a loop.
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
/// use rust_loops::l_factorial;
///
/// let result = l_factorial(5);
/// assert_eq!(result, 120); // Output: 120
/// ```
#[no_mangle]
pub extern "C" fn l_factorial(n: u64) -> u64 {
    if n > 20 {
        return 0;
    }

    let mut result = 1;

    for i in 1..=n {
        result *= i;
    }

    result
}

/// Calculate the greatest common divisor of two given integers using a loop.
///
/// # Arguments
///
/// * `a` - The first integer.
/// * `b` - The second integer.
///
/// # Returns
///
/// The greatest common divisor of the two given integers.
///
/// # Example
///
/// ```
/// use rust_loops::l_gcd;
///
/// let result = l_gcd(12, 18);
/// assert_eq!(result, 6); // Output: 6
/// ```
#[no_mangle]
pub extern "C" fn l_gcd(mut a: u64, mut b: u64) -> u64 {
    if a > b {
        std::mem::swap(&mut a, &mut b);
    }

    while a != 0 {
        let temp = a;
        a = b % a;
        b = temp;
    }

    b
}

#[repr(C)]
/// Represents the result of a linear diophantine equation solution.
pub struct LLinearSolution {
    /// Indicates if a solution exists.
    pub is_solution: bool,
    /// The solution for x.
    pub x: i64,
    /// The solution for y.
    pub y: i64,
}

/// Solve a linear diophantine equation of form ax + by = c using a loop.
///
/// # Arguments
///
/// * `a` - The coefficient of x.
/// * `b` - The coefficient of y.
/// * `c` - The constant value.
///
/// # Returns
///
/// A structure containing the solution of the linear diophantine equation.
///
/// # Example
///
/// ```
/// use rust_loops::l_solve_linear_diophantine;
///
/// let solution = l_solve_linear_diophantine(12, 15, 3);
/// if solution.is_solution {
///     assert_eq!(solution.x, -1);
///     assert_eq!(solution.y, 1);
///     println!("Solution: x = {}, y = {}", solution.x, solution.y); // Output: Solution: x = -1, y = 1
/// } else {
///     panic!("No solution found.");
/// }
/// ```
#[no_mangle]
pub extern "C" fn l_solve_linear_diophantine(mut a: i64, mut b: i64, c: i64) -> LLinearSolution {
    let (mut new_x, mut old_x) = (1, 0);
    let (mut new_y, mut old_y) = (0, 1);

    if a > b {
        std::mem::swap(&mut a, &mut b);
        new_x = 0;
        old_x = 1;
        new_y = 1;
        old_y = 0;
    }

    while a != 0 {
        let quotient = b / a;
        let remainder = b % a;

        let temp = new_x;
        new_x = old_x - quotient * new_x;
        old_x = temp;

        let temp = new_y;
        new_y = old_y - quotient * new_y;
        old_y = temp;

        b = a;
        a = remainder;
    }
    
    if c == 0 && a == 0 && b == 0 {
        LLinearSolution { is_solution: true, x: 0, y: 0 }
    } else if b != 0 && c % b == 0 {
        let k = c / b;
        old_x *= k;
        old_y *= k;
        LLinearSolution { is_solution: true, x: old_x, y: old_y }
    } else {
        LLinearSolution { is_solution: false, x: 0, y: 0 }
    }
}

