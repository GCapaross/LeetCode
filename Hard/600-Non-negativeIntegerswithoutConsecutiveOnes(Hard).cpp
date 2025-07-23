        // Think this might have some calculations associated with it
        // Seems unoptimal to be converting the numbers and then evaluating 1 by one and seeing and discarding "11"
        // 0:0 | 1:1 | 2:10 | 3:11 | 4:100 | 5:101 | 6:110 | 7:111 | 8:1000 | 9:1001 | 10:1010 | 11:1011
        // I could use <bitset> or manually convert to binary, but this seems unoptimal as I've said before
        // What I could do is, get the highest number meaning n
        // And from n
        // Example: n = 128 -> 0b10000000
        // I could apply combinations as a formula or calculate manually through iterations the number of combinations by replacing and summing
        // Thinking of building a graph where I calculate manually the max num of bits for and start building the tree from a 1, from left to right
        // 0 will always pass the condition so if n = 1 return 1
        // meaning initial value for sum = 1, so we can start the tree in 1 instead of 0
        // With 128, 10000000 -> tree starts and will always start in 1, then I go down the tree and I mark as visited, i need to traverse all nodes, and I subtract those with 2 ones in a row, if I have 1011... I know that all the others ones will be subtracted from 129 (128+1 because of 0)
        // Actually to optimize we'll just sum to those whose path can be followed therefore I dont need to keep traversing everything after discounting them

class Solution {
public:
    int findIntegers(int n) {
        count = 1; // count 0 separately since it's always valid
        dfs(1, 1, n); // start tree from 1 with previous bit = 1
        return count;
    }

private:
    int count = 0;

    void dfs(int curr, int prevBit, int n) {
        if (curr > n) return;

        count++; 

        // always try appending 0
        dfs((curr << 1), 0, n);

        // try appending 1 only if previous bit was 0
        if (prevBit == 0) {
            dfs((curr << 1) | 1, 1, n);
        }
    }
};

// After looking up my solution is very optimal in memory terms, beats 99%
// Fibonacci would be better for runtime
