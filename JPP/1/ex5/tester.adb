with Ada.Text_IO; use Ada.Text_IO;
with Interfaces; use Interfaces;

procedure Tester is
    type L_LinearSolution is record
        Is_Solution : Boolean;
        X : Integer_64;
        Y : Integer_64;
    end record
    with Convention => C;

    function l_factorial (n: Unsigned_64) return Integer_64
        with
        Import => True,
        Convention => C;

    function l_gcd (A, B : Unsigned_64) return Integer_64
        with
        Import => True,
        Convention => C;

    function l_solve_linear_diophantine (A, B, C : Integer_64) return L_LinearSolution
        with
        Import => True,
        Convention => C; 

    type R_LinearSolution is record
        Is_Solution : Boolean;
        X : Integer_64;
        Y : Integer_64;
    end record
    with Convention => C;

    function r_factorial (n: Unsigned_64) return Integer_64
        with
        Import => True,
        Convention => C;

    function r_gcd (A, B : Unsigned_64) return Integer_64
        with
        Import => True,
        Convention => C;

    function r_solve_linear_diophantine (A, B, C : Integer_64) return R_LinearSolution
        with
        Import => True,
        Convention => C; 

    Ii:  Unsigned_64;
    Solution : L_LinearSolution;
    Solution2 : R_LinearSolution;
begin
    Put_Line("Loops:");

    New_Line;

    for I in 0 .. 6 loop
        Ii := Unsigned_64(I) * 4;
        Put_Line("Factorial of " & Ii'Image & " is: " & l_factorial(Ii)'Image);
    end loop;

    New_Line;

    Put_Line("gcd(10, 5) = " & l_gcd(10, 5)'Image);
    Put_Line("gcd(14, 21) = " & l_gcd(14, 21)'Image);
    Put_Line("gcd(21, 14) = " & l_gcd(21, 14)'Image);

    New_Line;

    Solution := l_solve_linear_diophantine(46, 240, 8);
    Put_Line("For 46x + 240y = 8: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    Solution := l_solve_linear_diophantine(240, 46, 8);
    Put_Line("For 240x + 46y = 8: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    Solution := l_solve_linear_diophantine(240, 46, 7);
    Put_Line("For 240x + 46y = 7: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    Solution := l_solve_linear_diophantine(0, 0, 5);
    Put_Line("For 0x + 0y = 5: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    Solution := l_solve_linear_diophantine(0, 0, 0);
    Put_Line("For 0x + 0y = 0: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    New_Line;

    Put_Line("Recursion:");

    New_Line;

    for I in 0 .. 6 loop
        Ii := Unsigned_64(I) * 4;
        Put_Line("Factorial of " & Ii'Image & " is: " & r_factorial(Ii)'Image);
    end loop;

    New_Line;

    Put_Line("gcd(10, 5) = " & r_gcd(10, 5)'Image);
    Put_Line("gcd(14, 21) = " & r_gcd(14, 21)'Image);
    Put_Line("gcd(21, 14) = " & r_gcd(21, 14)'Image);

    New_Line;

    Solution2 := r_solve_linear_diophantine(46, 240, 8);
    Put_Line("For 46x + 240y = 8: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

    Solution2 := r_solve_linear_diophantine(240, 46, 8);
    Put_Line("For 240x + 46y = 8: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

    Solution2 := r_solve_linear_diophantine(240, 46, 7);
    Put_Line("For 240x + 46y = 7: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

    Solution2 := r_solve_linear_diophantine(0, 0, 5);
    Put_Line("For 0x + 0y = 5: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

    Solution2 := r_solve_linear_diophantine(0, 0, 0);
    Put_Line("For 0x + 0y = 0: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

end Tester;

