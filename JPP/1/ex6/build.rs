fn main() {
    println!("cargo:rustc-flags=-l math_c_loops -L ../ex1/c_loops");
    println!("cargo:rustc-flags=-l math_c_recursion -L ../ex1/c_recursion");
}
