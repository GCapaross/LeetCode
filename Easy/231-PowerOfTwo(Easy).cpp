// One liner through bit manipulation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};


// Logaritmic method
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if (n <= 0) return false;
//         double logVal = log2(n);
//         return floor(logVal) == logVal;
//     }
// };

// Looping option
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if (n <= 0) return false; 
//         while (n % 2 == 0) {
//             n /= 2;
//         }
//         return n == 1;
//     }
// };
