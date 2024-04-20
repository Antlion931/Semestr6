with Interfaces; use Interfaces;
with Ada.Text_IO; use Ada.Text_IO;

package Ada_Recursion is
    function R_Factorial(N : Unsigned_64) return Unsigned_64
        with Export =>  True,
            Convention => C,
            External_Name => "r_factorial";

    function R_GCD(A, B : Unsigned_64) return Unsigned_64
        with Export =>  True,
            Convention => C,
            External_Name => "r_gcd";

    type R_Linear_Solution is record
        Is_Solution : Boolean;
        X : Integer_64;
        Y : Integer_64;
    end record
    with Convention => C;

    function R_Solve_Linear_Diophantine(A, B, C : Integer_64) return R_Linear_Solution
        with Export =>  True,
            Convention => C,
            External_Name => "r_solve_linear_diophantine";

end Ada_Recursion;

