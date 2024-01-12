use num::bigint::{BigUint, ToBigUint};

fn factorial(number: &BigUint) -> Option<BigUint> {
    if number%2u32 != num::zero() {
        return None;
    }
    let tmpa = number.clone()/2u32;
    let mut tmpb = tmpa.clone() * (tmpa.clone()+1u32);
    let mut tmpc = 0u32;
    let mut res = num::one();
    while tmpb >= *number {
        res *= tmpb.clone();
        println!("{}", tmpb);
        tmpc += 1u32;
        tmpb -= 2u32 * tmpc;
    }
    Some(res)
}

fn main() {
    let number = 100.to_biguint().unwrap();
    if let Some(v) = factorial(&number) {
        let s = v.to_str_radix(10);
        println!("{}", s);
        let mut sum = 0;
        for c in s.chars() {
            let d = c.to_digit(10).unwrap();
            sum += d;
        }
        println!("{}", sum);
    }
    else {
        eprintln!("Fail");
    }
}
