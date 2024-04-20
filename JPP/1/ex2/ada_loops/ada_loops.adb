package body Ada_Loops is

    function L_Factorial(N : Unsigned_64) return Unsigned_64 is
        Result : Unsigned_64 := 1;
    begin
        if N > 20 then
            return 0;
        end if;

        for I in 1 .. N loop
            Result := Result * I;
        end loop;

        return Result;
    end L_Factorial;

    function L_GCD(A, B : Unsigned_64) return Unsigned_64 is
        Temp,  Ac, Bc : Unsigned_64;
    begin
        Ac := A;
        Bc := B;

        if Ac > Bc then
            Temp := Ac;
            Ac := Bc;
            Bc := Temp;
        end if;

        while Ac /= 0 loop
            Temp := Ac;
            Ac := Bc mod Ac;
            Bc := Temp;
        end loop;

        return Bc;
    end L_Gcd;

    function L_Solve_Linear_Diophantine(A, B, C : Integer_64) return L_Linear_Solution is
        New_X, Old_X, New_Y, Old_Y, Quotient, Remainder, K, Temp, Ac, Bc: Integer_64;
    begin
        New_X := 1;
        Old_X := 0;
        New_Y := 0;
        Old_Y := 1;

        Ac := A;
        Bc := B;

        if Ac > Bc then
            Temp := Ac;
            Ac := Bc;
            Bc := Temp;

            New_X := 0;
            Old_X := 1;
            New_Y := 1;
            Old_Y := 0;
        end if;

        while Ac /= 0 loop
            Quotient := Bc / Ac;
            Remainder := Bc mod Ac;

            Temp := New_X;
            New_X := Old_X - Quotient * New_X;
            Old_X := Temp;

            Temp := New_Y;
            New_Y := Old_Y - Quotient * New_Y;
            Old_Y := Temp;

            Bc := Ac;
            Ac := Remainder;
        end loop;

        if C = 0 and Ac = 0 and Bc = 0 then
            return (True, 0, 0);
        elsif Bc /= 0 and then C mod Bc = 0 then
            K := C / Bc;
            Old_X := Old_X * K;
            Old_Y := Old_Y * K;
            return (True, Old_X, Old_Y);
        else
            return (False, 0, 0);
        end if;
    end L_Solve_Linear_Diophantine;

end Ada_Loops;

