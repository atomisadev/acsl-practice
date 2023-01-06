use std::env;
use std::error::Error;
use std::fs::File;
use std::io::{BufRead, BufReader, Write};
use std::str::FromStr;

fn transform(n: i32, p: i32) -> i32 {
    let s = n.to_string();
    let pth_digit = (s.chars().nth(s.len() - p as usize).unwrap() as i32) - ('0' as i32);
    let transformed: String = s.chars()
        .enumerate()
        .map(|(i, c)| {
            let digit = c as i32 - ('0' as i32);
            if i < s.len() - p as usize {
                ((digit + pth_digit) % 10 + ('0' as i32)) as u8 as char
            } else if i > s.len() - p as usize {
                (digit.abs() + ('0' as i32)) as u8 as char
            } else {
                c
            }
        })
        .collect();
    i32::from_str(&transformed).unwrap()
}

fn main() -> Result<(), Box<dyn Error>> {
    let input_file = env::args().nth(1).ok_or("Error: No input file provided.")?;
    let file = File::open(input_file)?;
    let reader = BufReader::new(file);
    for line in reader.lines() {
        let line = line?;
        let mut parts = line.split(' ');
        let n = parts.next().ok_or("Error: Invalid input format.")?.parse()?;
        let p = parts.next().ok_or("Error: Invalid input format.")?.parse()?;
        println!("{}", transform(n, p));
    }
    Ok(())
}
