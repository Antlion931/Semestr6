#[repr(C)]
pub struct L_LinearSolution {
    pub is_solution: bool,
    pub x: i64,
    pub y: i64,
}

#[repr(C)]
pub struct R_LinearSolution {
    pub is_solution: bool,
    pub x: i64,
    pub y: i64,
}

extern "C" {
    pub fn l_factorial(n: u64) -> u64;
    pub fn l_gcd(a: u64, b: u64) -> u64;
    pub fn l_solve_linear_diophantine (a: i64, b: i64, c: i64) -> L_LinearSolution;

    pub fn r_factorial(n: u64) -> u64;
    pub fn r_gcd(a: u64, b: u64) -> u64;
    pub fn r_solve_linear_diophantine (a: i64, b: i64, c: i64) -> R_LinearSolution;
}


fn main() {
    unsafe {
        println!("Loops:\n");

        for i in (0..25).step_by(4) {
            println!("Factorial of {} is: {}", i, l_factorial(i));
        }

        println!();

        println!("gcd(10, 5) = {}", l_gcd(10, 5));
        println!("gcd(14, 21) = {}", l_gcd(14, 21));
        println!("gcd(21, 14) = {}", l_gcd(21, 14));

        println!();

        {
            let solution = l_solve_linear_diophantine(46, 240, 8);
            println!("For 46x + 240y = 8: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);

            let solution = l_solve_linear_diophantine(240, 46, 8);
            println!("For 240x + 46y = 8: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);

            let solution = l_solve_linear_diophantine(240, 46, 7);
            println!("For 240x + 46y = 7: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);

            let solution = l_solve_linear_diophantine(0, 0, 5);
            println!("For 0x + 0y = 5: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);

            let solution = l_solve_linear_diophantine(0, 0, 0);
            println!("For 0x + 0y = 0: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);
        }

        println!("\nRecursion:\n");

        for i in (0..25).step_by(4) {
            println!("Factorial of {} is: {}", i, r_factorial(i));
        }

        println!();

        println!("gcd(10, 5) = {}", r_gcd(10, 5));
        println!("gcd(14, 21) = {}", r_gcd(14, 21));
        println!("gcd(21, 14) = {}", r_gcd(21, 14));

        println!();

        {
            let solution = r_solve_linear_diophantine(46, 240, 8);
            println!("For 46x + 240y = 8: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);

            let solution = r_solve_linear_diophantine(240, 46, 8);
            println!("For 240x + 46y = 8: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);

            let solution = r_solve_linear_diophantine(240, 46, 7);
            println!("For 240x + 46y = 7: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);

            let solution = r_solve_linear_diophantine(0, 0, 5);
            println!("For 0x + 0y = 5: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);

            let solution = r_solve_linear_diophantine(0, 0, 0);
            println!("For 0x + 0y = 0: is_solution = {}, x = {}, y = {}", solution.is_solution, solution.x, solution.y);
        }
    }
}

