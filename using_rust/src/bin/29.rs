use std::collections::HashSet;
use using_rust::p29::Factor;

fn main() {
    let mut unique_value: HashSet<Vec<Factor>> = HashSet::new();
    let mut factors: Vec<Factor> = Vec::with_capacity(100);
    for a in 2..=100 {
        Factor::factorize(a, &mut factors);
        println!("{} {:?}", a, factors);
        for b in 2..=100 {
            for factor in factors.iter_mut() {
                factor.exp *= b;
            }
            if !unique_value.contains(&factors) {
                unique_value.insert(factors.clone());
            }
            for factor in factors.iter_mut() {
                factor.exp /= b;
            }
        }
    }
    println!("{}", unique_value.len());
}