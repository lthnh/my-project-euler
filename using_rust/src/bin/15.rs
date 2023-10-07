use std::io::{self, Write};
use std::collections::VecDeque; 

struct Point(i32, i32);

const NUMBER_OF_MOVEMENT: usize = 2;
const DIRECTION_VERTICAL: [i32; NUMBER_OF_MOVEMENT] = [1, 0];
const DIRECTION_HORIZONTAL: [i32; NUMBER_OF_MOVEMENT] = [0, 1];

impl PartialEq for Point {
    fn eq(&self, other: &Self) -> bool {
        self.0 == other.0 && self.1 == other.1
    }
}

fn read_n() -> i32 {
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

fn depth_first_search(n: i32) -> i32 {
    let mut solutions_count = 0;
    let mut stack: VecDeque<Point> = VecDeque::new();
    stack.push_front(Point(0, 0));
    while !stack.is_empty() {
        let Point(x, y) = stack.pop_front().unwrap();
        println!("{} {}", x, y);
        for i in 0..NUMBER_OF_MOVEMENT {
            let new_x = x + DIRECTION_HORIZONTAL[i];
            let new_y = y + DIRECTION_VERTICAL[i];
            if new_x < 0 || new_x > n || new_y < 0 || new_y > n {
                continue;
            }
            if Point(new_x, new_y) == Point(n, n) {
                solutions_count += 1;
                continue;
            } else {
                stack.push_front(Point(new_x, new_y));
            }
        }
    }
    solutions_count
}

fn main() {
    let n = read_n();
    let solutions_count = depth_first_search(n);
    println!("{} path(s)", solutions_count);
}