pub fn binary_exponation(mut base: u64, mut exp: u32) -> u64 {
    let mut result: u64 = 1;

    while exp > 0 {
        if exp & 1 == 1 {
            result *= base;
        }

        base *= base;
        exp '/= 1;
    }

    result
}