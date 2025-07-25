impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        let lg = (n as f64).log2();

        lg.fract() == 0.0
    }
}
