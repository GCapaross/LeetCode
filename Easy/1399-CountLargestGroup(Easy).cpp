class Solution {

    // I'm trying to optimize the exercise, and the first way I tried to solve it I overlooked some things, I don't wanna be traversing the numbers
    // And doing unnecessary iterations, I'm trying to find a formula
    // n = 100
    // Sum = 1:  [1, 10, 100]
    // Sum = 2:  [2, 11, 20]
    // Sum = 3:  [3, 12, 21, 30]
    // Sum = 4:  [4, 13, 22, 31, 40]
    // Sum = 5:  [5, 14, 23, 32, 41, 50]
    // Sum = 6:  [6, 15, 24, 33, 42, 51, 60]
    // Sum = 7:  [7, 16, 25, 34, 43, 52, 61, 70]
    // Sum = 8:  [8, 17, 26, 35, 44, 53, 62, 71, 80]
    // Sum = 9:  [9, 18, 27, 36, 45, 54, 63, 72, 81, 90]
    // Sum = 10: [19, 28, 37, 46, 55, 64, 73, 82, 91]
    // Sum = 11: [29, 38, 47, 56, 65, 74, 83, 92]
    // Sum = 12: [39, 48, 57, 66, 75, 84, 93]
    // Sum = 13: [49, 58, 67, 76, 85, 94]
    // Sum = 14: [59, 68, 77, 86, 95]
    // Sum = 15: [69, 78, 87, 96]
    // Sum = 16: [79, 88, 97]
    // Sum = 17: [89, 98]
    // Sum = 18: [99]
    // It keeps incrementing in a pyramid scheme
    // And this also clears the doubt if we have n = 19 -> 1 + 9 = 10 -> should be taken as sum = 10 and not 1 + 0
    // From this example we can see, numbers whereas the sum amounts to something higher than 10 which occurs after 28
    // Are never possible to become apart of the groups of largest size
    // We notice that 9 will almost always be the biggest singular group




public:
    int countLargestGroup(int n) {
        // Count how many digit sum groups have the maximum group size
        unordered_map<int, int> digitSumCount;
        
        // Count frequency of each digit sum
        for (int i = 1; i <= n; i++) {
            int sum = digitSum(i);
            digitSumCount[sum]++;
        }
        
        // Find the maximum group size
        int maxSize = 0;
        for (auto& pair : digitSumCount) {
            maxSize = max(maxSize, pair.second);
        }
        
        // Count how many groups have this maximum size
        int result = 0;
        for (auto& pair : digitSumCount) {
            if (pair.second == maxSize) {
                result++;
            }
        }
        
        return result;
    }
    
private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};












    // int countLargestGroup(int n) {
    //     // Instead of doing calculations and enumerating all the numbers
    //     // I'll do the following
        
    //     // Because like this there will be no overlapping nor other numbers getting added to groups
    //     if (n < 10) {
    //         return n;
    //     }

    //     // After this:
    //     // I'll do a loop
    //     // Where I'll increment always the division to 10
    //     // And use the rest to divide the groups
    //     // Actually wait
    //     // I don't even need to traverse I just need n and do the rest of division plus 1

    //     // For example:
    //     // n = 24 -> 24 % 10 = 4 -> 4 + 1 = 5
    //     // [1,10,19], [2,11,20], [3,12,21], [4,13,22]
    //     int remainder = n % 10;
    //     int size = remainder + 1;
    //     return size;
    // }



// Ill comeback to this solutino later
// We know that we need to find the highest number sum for example n = 1000 -> n = 999 is the highest sum for 27 if it would be 2+7 it would be 
// much easier to solve
// But the peak is in 13 or 14 depending how would we calculate that...
// class Solution {
// public:
//     int countLargestGroup(int n) {
//         if (n < 10) return n;
        
//         // Find the maximum possible digit sum for numbers up to n
//         int maxDigitSum = digitSum(n);
        
//         // The pyramid peaks at roughly the middle of the range [1, maxDigitSum]
//         int peakDigitSum = (1 + maxDigitSum) / 2;
//         // Or more precisely: maxDigitSum / 2 (since min is effectively 1)
        
//         // For most cases, this peak digit sum will have the unique maximum count
//         // The pyramid structure ensures typically only 1 group has the maximum
        
//         // However, we need to handle edge cases where we "cut" the pyramid
//         // during its building phase, creating ties
        
//         // Let's analyze the specific patterns:
        
//         if (n == 999) {
//             // maxDigitSum = 27, peak around 13-14
//             // From your analysis, digit sum 13 or 14 should win uniquely
//             return 1;
//         }
        
//         // The mathematical insight:
//         // - If n allows the pyramid to "complete" near its peak → answer = 1
//         // - If n "cuts" the pyramid while ascending → multiple ties possible
        
//         // We can determine this by checking if n includes enough numbers
//         // to reach the natural peak of the digit sum distribution
        
//         return calculatePyramidPeak(n, maxDigitSum);
//     }
    
// private:
//     int digitSum(int num) {
//         int sum = 0;
//         while (num > 0) {
//             sum += num % 10;
//             num /= 10;
//         }
//         return sum;
//     }
    
//     int calculatePyramidPeak(int n, int maxDigitSum) {
//         // The peak occurs around maxDigitSum / 2
//         int expectedPeak = maxDigitSum / 2;
        
//         // Check if n is large enough to reach this natural peak
//         // If yes, typically return 1 (unique maximum)
//         // If no, we might have ties
        
//         // For competitive programming ranges, most cases return 1
//         // because the pyramid structure creates a unique peak
        
//         // Special handling for small ranges where ties occur:
//         if (n <= 20) {
//             // In early pyramid building, multiple ties are common
//             // Need more precise calculation here
//             return bruteForcePeak(n);
//         }
        
//         // For larger n, the pyramid effect dominates → unique peak
//         return 1;
//     }
    
//     int bruteForcePeak(int n) {
//         // Fallback for edge cases - calculate exactly
//         unordered_map<int, int> count;
//         for (int i = 1; i <= n; i++) {
//             count[digitSum(i)]++;
//         }
        
//         int maxCount = 0;
//         for (auto& p : count) {
//             maxCount = max(maxCount, p.second);
//         }
        
//         int result = 0;
//         for (auto& p : count) {
//             if (p.second == maxCount) result++;
//         }
        
//         return result;
//     }
// };
