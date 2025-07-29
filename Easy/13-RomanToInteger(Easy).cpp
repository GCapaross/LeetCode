class Solution {
public:

    // Best solution in terms of memory, but very extense and hard coded, a map would be easier
    // Actually in reruns it can get 0ms and beats 100% in memory and runtime
    int romanToInt(string s) {
        int sum = 0;
        int i = 0;

        while (i < s.length()) {
            if (s[i] == 'M') {
                sum += 1000;
                i++;
            } else if (s[i] == 'D') {
                sum += 500;
                i++;
            } else if (s[i] == 'C') {
                if (i + 1 < s.length() && s[i + 1] == 'M') {
                    sum += 900;
                    i += 2;
                } else if (i + 1 < s.length() && s[i + 1] == 'D') {
                    sum += 400;
                    i += 2;
                } else {
                    sum += 100;
                    i++;
                }
            } else if (s[i] == 'L') {
                sum += 50;
                i++;
            } else if (s[i] == 'X') {
                if (i + 1 < s.length() && s[i + 1] == 'C') {
                    sum += 90;
                    i += 2;
                } else if (i + 1 < s.length() && s[i + 1] == 'L') {
                    sum += 40;
                    i += 2;
                } else {
                    sum += 10;
                    i++;
                }
            } else if (s[i] == 'V') {
                sum += 5;
                i++;
            } else if (s[i] == 'I') {
                if (i + 1 < s.length() && s[i + 1] == 'X') {
                    sum += 9;
                    i += 2;
                } else if (i + 1 < s.length() && s[i + 1] == 'V') {
                    sum += 4;
                    i += 2;
                } else {
                    sum += 1;
                    i++;
                }
            }
        }

        return sum;
    }
};
