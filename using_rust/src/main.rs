use std::io::{self, Write};

fn read_test() -> i32 {
    print!("N: ");
    io::stdout()
        .flush()
        .unwrap();
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .unwrap();
    let n = input.trim().parse().unwrap();
    n
}

fn main() {
    let n = read_test();
    println!("{}", n);
}
