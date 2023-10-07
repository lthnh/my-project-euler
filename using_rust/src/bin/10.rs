fn main() {
    const LIMIT: u64 = 2e6 as u64;
    let mut is_prime: [bool; (LIMIT-1) as usize] = [true; (LIMIT-1) as usize];
    let mut sum_prime = 0 as u64;
    let mut last_number = 0 as u64;
    for i in (2u64..).take_while(|&x| x.pow(2) <= LIMIT) {
        if is_prime[(i-2) as usize] == true {
            sum_prime += i;
            last_number = i;
            let mut j = i.pow(2);
            while j <= LIMIT {
                is_prime[(j-2) as usize] = false;
                j += i;
            }
        }
    }
    for i in last_number+1..=LIMIT {
        if is_prime[(i-2) as usize] == true {
            sum_prime += i;
        }
    }
    println!("{}", sum_prime);
}