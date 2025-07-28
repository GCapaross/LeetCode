class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // Sliding window problem

        int n = blocks.length();
        int currentW = 0;
        int transformations = k;

        // Let's first count the number of W's in a row
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                currentW++;
            } 
        }

        transformations = currentW;

        for (int i = k; i < n; i++) {
            if (blocks[i - k] == 'W') currentW--;
            if (blocks[i] == 'W') currentW++;

            transformations = min(transformations, currentW);
        }

        return transformations;
    }
};
