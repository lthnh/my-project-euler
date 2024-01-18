use std::fs;

fn main() {
    let file_path = "/home/anhle/project-euler/using_rust/0022_names.txt";
    let contents = fs::read_to_string(file_path).unwrap();
    println!("{}", contents);
    let mut name_list = Vec::new();
    for name in contents.split(",") {
        let processed_name = name
            .trim()
            .strip_prefix("\"").unwrap()
            .strip_suffix("\"").unwrap();
        name_list.push(processed_name);
    }
    let mut val_total = 0;
    name_list.sort();
    for (pos, name ) in name_list.iter().enumerate() {
        println!("{} {}", pos + 1, name);
        let mut val_sum = 0;
        for c in name.chars() {
            let val = c as u32 - 64;
            val_sum += val;
        }
        val_sum *= (pos + 1) as u32;
        println!("{}", val_sum);
        val_total += val_sum;
    }
    println!("{}", val_total);
}
