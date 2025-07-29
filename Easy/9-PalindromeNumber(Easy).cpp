// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) {
//             return false;
//         }

//         int n = x;
//         int reverse = 0;

//         while (n != 0) {
//             int digit = n % 10;

//             if (reverse > (INT_MAX - digit) / 10) {
//                 return false; // would overflow
//             }

//             reverse = reverse * 10 + digit;
//             n = n / 10;
//         }

//         return reverse == x;
//     }
// };


// Or check size and transform to string


        // Another way would be take the number putting it in an array pushed back and then comparing strings

        // vector<char> word;
        // string number = to_string(x);
        
        // for (char c : number) {
        //     word.push_back(c);
        // }


        // reverse(word.begin(), word.end());
        // string s(word.begin(), word.end());


        // std::cout << "String:" << s;
        // std::cout << "String:" << number;

        // if (s == number) return true;


        // return false;

        // Other solutinon





class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;  

        string s = to_string(x);
        int n = s.length();

        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }

        return true;
    }
};
