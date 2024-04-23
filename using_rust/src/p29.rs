#[derive(Hash, PartialEq, Eq, Clone, Copy, Debug)]
pub struct Factor { pub base: i32, pub exp: i32 }

impl Factor {
    fn is_prime(base: i32) -> bool {
        let mut prime = true;
        if base > 1 {
            for i in 2..=base/2 {
                if base%i  == 0 {
                    prime = false;
                    break;
                }
            }
        } else {
            prime = false;
        }
        prime
    }

    pub fn factorize(mut n: i32, factors: &mut Vec<Self>) {
        if !factors.is_empty() {
            factors.clear();
        }
        let l = n/2;
        if [0, 1, 2, 3, 5, 7].contains(&n) {
            factors.push(Factor { base: n, exp: 1 });
            n = 1;
        }
        for i in 2..=l {
            if n%i == 0 && Self::is_prime(i) {
                factors.push(Factor { base: i, exp: 0 });
                while n%i == 0 {
                    factors.last_mut().unwrap().exp += 1;
                    n /= i;
                }
            }
        }
        if n > 1 {
            factors.push(Factor { base: n, exp: 1 });
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Factor;

    #[test]
    fn correct_prime() {
        let small_prime = [2, 3, 5, 7];
        for &p in small_prime.iter() {
            assert_eq!(true, Factor::is_prime(p), "testing with {}", p);
        }
        for np in (0..=10).filter(|x| !small_prime.contains(x)) {
            assert_eq!(false, Factor::is_prime(np), "testing with {}", np);
        }
    }

    #[test]
    fn correct_factorize() {
        let small_prime = [2, 3, 5, 7];
        let mut factors = Vec::<Factor>::with_capacity(100);
        for &p in small_prime.iter() {
            Factor::factorize(p, &mut factors);
            assert_eq!(vec![Factor { base: p, exp: 1 }], factors);
        }
        for np in (0..=10).filter(|x| !small_prime.contains(x)) {
            Factor::factorize(np, &mut factors);
            match np {
                0 => assert_eq!(vec![Factor { base: 0, exp: 1 }], factors),
                1 => assert_eq!(vec![Factor { base: 1, exp: 1 }], factors),
                4 => assert_eq!(vec![Factor { base: 2, exp: 2 }], factors),
                6 => assert_eq!(vec![Factor { base: 2, exp: 1 }, Factor { base: 3, exp: 1}], factors),
                8 => assert_eq!(vec![Factor { base: 2, exp: 3 }], factors),
                9 => assert_eq!(vec![Factor { base: 3, exp: 2 }], factors),
                10 => assert_eq!(vec![Factor { base: 2, exp: 1 }, Factor { base: 5, exp: 1 }], factors),
                _ => todo!()
            }
        }
        Factor::factorize(31, &mut factors);
        assert_eq!(vec![Factor { base: 31, exp: 1 }], factors);
    }
}