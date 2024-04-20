use rust_loops::{l_factorial, l_gcd, l_solve_linear_diophantine};
use rust_recursion::{r_factorial, r_gcd, r_solve_linear_diophantine};

fn main() {
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

