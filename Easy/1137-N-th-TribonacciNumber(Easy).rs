impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let mut dp = vec![0; (n + 1) as usize];

        dp[0] = 0;
        if n > 0 {
            dp[1] = 1;
        }
        if n > 1 {
            dp[2] = 1;
        }

        if n == 0 || n == 1 || n == 2 {
            return dp[n as usize];
        }

        for i in 3..=n {
            dp[i as usize] = dp[i as usize - 1] + dp[i as usize - 2] + dp[i as usize - 3];
        }

        dp[n as usize]
    }
}
