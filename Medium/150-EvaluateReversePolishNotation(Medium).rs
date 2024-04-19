use std::collections::VecDeque;

impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack = VecDeque::new();

        for token in tokens {
            match token.as_str() {
                "*" | "-" | "+" | "/" => {
                    let operand2 = stack.pop_back().unwrap();
                    let operand1 = stack.pop_back().unwrap();

                    let result = match token.as_str() {
                        "*" => operand1 * operand2,
                        "-" => operand1 - operand2,
                        "+" => operand1 + operand2,
                        "/" => operand1 / operand2,
                        _ => unreachable!(),
                    };

                    stack.push_back(result);
                }
                _ => {
                    let number = token.parse::<i32>().unwrap();
                    stack.push_back(number);
                }
            }
        }

        stack.pop_back().unwrap()
    }
}
