with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Text_IO; use Ada.Text_IO;


package body Ada_Recursion is
function Factorial_Recursive(N : Unsigned_64) return Unsigned_64 is
begin
  if N = 0 then
     return 1;
  end if;

  return N * Factorial_Recursive(N - 1);
end Factorial_Recursive;

   function R_Factorial(N : Unsigned_64) return Unsigned_64 is
   begin
      if N > 20 then
         return 0;
      end if;

      return Factorial_Recursive(N);
   end R_Factorial;

   function R_GCD(A, B : Unsigned_64) return Unsigned_64 is
   begin
      if B = 0 then
         return A;
      end if;

     return R_GCD(B, A mod B);
   end R_GCD;

   type Extended_GCD_Result is record
      GCD : Integer_64;
      X : Integer_64;
      Y : Integer_64;
   end record;

   function Extended_GCD(A, B : Integer_64) return Extended_GCD_Result is
   Result : Extended_GCD_Result; 
   begin
      if B = 0 then
         return (A, 1, 0);
      end if;
      Result := Extended_GCD(B, A mod B);

    return (Result.GCD, Result.Y, Result.X - (A / B) * Result.Y);
   end Extended_GCD;

   function R_Solve_Linear_Diophantine(A, B, C : Integer_64) return R_Linear_Solution is
      Result_Extended : Extended_GCD_Result;
   begin
      if A = 0 and B = 0 then
         return (C = 0, 0, 0);
      end if;

    Result_Extended := Extended_GCD(A, B);
    if C mod Result_Extended.Gcd /= 0 then
       return (False, 0, 0);
    end if;

   return (True, Result_Extended.X * (C / Result_Extended.Gcd), Result_Extended.Y * (C / Result_Extended.Gcd));
   end R_Solve_Linear_Diophantine;
   
end Ada_Recursion;
