with Interfaces; use Interfaces;
with Ada.Text_IO; use Ada.Text_IO;

package Ada_Loops is

    function L_Factorial(N : Unsigned_64) return Unsigned_64
        with Export =>  True,
            Convention => C,
            External_Name => "l_factorial";

    function L_GCD(A, B : Unsigned_64) return Unsigned_64
        with Export =>  True,
            Convention => C,
            External_Name => "l_gcd";

    type L_Linear_Solution is record
        Is_Solution : Boolean;
        X : Integer_64;
        Y : Integer_64;
    end record
    with Convention => C;

    function L_Solve_Linear_Diophantine(A, B, C : Integer_64) return L_Linear_Solution
        with Export =>  True,
            Convention => C,
            External_Name => "l_solve_linear_diophantine";

end Ada_Loops;
