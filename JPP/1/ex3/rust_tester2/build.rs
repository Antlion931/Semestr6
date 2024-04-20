fn main() {
    println!("cargo:rustc-flags=-l rust_loops -L ../rust_loops/target/debug/");
    println!("cargo:rustc-flags=-l rust_recursion -L ../rust_recursion/target/debug/");
}
