pub fn arithmetic_series(n: u64, a1: i64) -> i64 {
    let serie = a1 + an;

    if n&1 == 0 {
        (n>>1) as i64 * serie 
    } else {
        n as i64 * (serie>>1)
    }
}