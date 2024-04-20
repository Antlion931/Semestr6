with Ada_Loops; use Ada_Loops;
with Ada_Recursion; use Ada_Recursion;
with Ada.Text_IO; use Ada.Text_IO;
with Interfaces; use Interfaces;

procedure Tester is
    Ii:  Unsigned_64;
    Solution : L_Linear_Solution;
    Solution2 : R_Linear_Solution;
    
begin
    Put_Line("Loops:");

    New_Line;

    for I in 0 .. 6 loop
        Ii := Unsigned_64(I) * 4;
        Put_Line("Factorial of " & Ii'Image & " is: " & L_Factorial(Ii)'Image);
    end loop;

    New_Line;

    Put_Line("gcd(10, 5) = " & L_GCD(10, 5)'Image);
    Put_Line("gcd(14, 21) = " & L_GCD(14, 21)'Image);
    Put_Line("gcd(21, 14) = " & L_GCD(21, 14)'Image);

    New_Line;

    Solution := L_Solve_Linear_Diophantine(46, 240, 8);
    Put_Line("For 46x + 240y = 8: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    Solution := L_Solve_Linear_Diophantine(240, 46, 8);
    Put_Line("For 240x + 46y = 8: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    Solution := L_Solve_Linear_Diophantine(240, 46, 7);
    Put_Line("For 240x + 46y = 7: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    Solution := L_Solve_Linear_Diophantine(0, 0, 5);
    Put_Line("For 0x + 0y = 5: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    Solution := L_Solve_Linear_Diophantine(0, 0, 0);
    Put_Line("For 0x + 0y = 0: is_solution = " & Solution.Is_Solution'Image & ", x = " & Solution.X'Image & ", y = " & Solution.Y'Image);

    New_Line;

    Put_Line("Recursion:");

    New_Line;

    for I in 0 .. 6 loop
        Ii := Unsigned_64(I) * 4;
        Put_Line("Factorial of " & Ii'Image & " is: " & R_Factorial(Ii)'Image);
    end loop;

    New_Line;

    Put_Line("gcd(10, 5) = " & R_GCD(10, 5)'Image);
    Put_Line("gcd(14, 21) = " & R_GCD(14, 21)'Image);
    Put_Line("gcd(21, 14) = " & R_GCD(21, 14)'Image);

    New_Line;

    Solution2 := R_Solve_Linear_Diophantine(46, 240, 8);
    Put_Line("For 46x + 240y = 8: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

    Solution2 := R_Solve_Linear_Diophantine(240, 46, 8);
    Put_Line("For 240x + 46y = 8: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

    Solution2 := R_Solve_Linear_Diophantine(240, 46, 7);
    Put_Line("For 240x + 46y = 7: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

    Solution2 := R_Solve_Linear_Diophantine(0, 0, 5);
    Put_Line("For 0x + 0y = 5: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

    Solution2 := R_Solve_Linear_Diophantine(0, 0, 0);
    Put_Line("For 0x + 0y = 0: is_solution = " & Solution2.Is_Solution'Image & ", x = " & Solution2.X'Image & ", y = " & Solution2.Y'Image);

end Tester;

