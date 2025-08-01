class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        return generatePascal(numRows);
    }

private:
    vector<vector<int>> generatePascal(int numRows) {
        if (numRows == 1) {
            return {{1}};
        }

        vector<vector<int>> result = generatePascal(numRows - 1);
        vector<int> prevRow = result.back();
        vector<int> currentRow;
        currentRow.push_back(1);

        for (int i = 1; i < prevRow.size(); ++i) {
            currentRow.push_back(prevRow[i - 1] + prevRow[i]);
        }

        currentRow.push_back(1);
        result.push_back(currentRow);

        return result;
    }
};
