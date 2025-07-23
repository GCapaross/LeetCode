// This solution was inefficient
// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         // Removing "ab" corresponds to x
//         // Removing "ba" corresponds to y
//         // Need to have in consideration when removing one it might give opportunities to another one
//         // Start by removing what gives more points, and traversing the string always looking for the most amount of points
//         string xab = "ab";
//         string yba = "ba";
//         int sum = 0;
//         string new_s = s;

//         bool removed = true; // flag to exit the while loop when nothing is removed

//         while (removed) {
//             removed = false;

//             if (x >= y) {
//                 for (int i = 0; i < new_s.length() - 1; i++) {
//                     string pair = new_s.substr(i, 2);
//                     if (pair == xab) {
//                         sum += x;
//                         new_s.erase(i, 2);
//                         removed = true;
//                         break;
//                     }
//                 }

//                 if (!removed) {
//                     for (int i = 0; i < new_s.length() - 1; i++) {
//                         string pair = new_s.substr(i, 2);
//                         if (pair == yba) {
//                             sum += y;
//                             new_s.erase(i, 2);
//                             removed = true;
//                             break;
//                         }
//                     }
//                 }

//             } else {
//                 for (int i = 0; i < new_s.length() - 1; i++) {
//                     string pair = new_s.substr(i, 2);
//                     if (pair == yba) {
//                         sum += y;
//                         new_s.erase(i, 2);
//                         removed = true;
//                         break;
//                     }
//                 }

//                 if (!removed) {
//                     for (int i = 0; i < new_s.length() - 1; i++) {
//                         string pair = new_s.substr(i, 2);
//                         if (pair == xab) {
//                             sum += x;
//                             new_s.erase(i, 2);
//                             removed = true;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }

//         return sum;
//     }
// };

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // We still start by removing the pair with the highest score first either x ab or y ba

        // Lambda function in cpp
        auto removePair = [](string &str, char first, char second, int score) {
            stack<char> st;
            int localSum = 0;


            // We check if the stack is or not empty, and if the top of the stack and the second upcoming character is part of the pair, we pop it
            for (char c : str) {
                if (!st.empty() && st.top() == first && c == second) {
                    st.pop();
                    localSum += score;
                } else {
                    st.push(c);
                }
            }

            // By popping the characters they come in reverse order so we use rebuilt to use reverse and correct the str
            string rebuilt;
            while (!st.empty()) {
                rebuilt += st.top();
                st.pop();
            }
            reverse(rebuilt.begin(), rebuilt.end());
            str = rebuilt;

            return localSum;
        };

        // End of function
        
        int total = 0;

        if (x >= y) {
            total += removePair(s, 'a', 'b', x);
            total += removePair(s, 'b', 'a', y);
        } else {
            total += removePair(s, 'b', 'a', y);
            total += removePair(s, 'a', 'b', x);
        }

        return total;
    }
};
