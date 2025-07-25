class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        // string chars[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
        // string c1 = "", c2 = "";

        // if (coordinate1 == coordinate2) {
        //     return true;
        // }

        // for (int i = 0; i < 8; i++) {
        //     if (chars[i][0] == coordinate1[0]) {
        //         int rest = i % 2;
        //         int row = coordinate1[1] - '0';  // Convert char to int
        //         if ((rest == 0 && row % 2 == 1) || (rest == 1 && row % 2 == 0)) {
        //             c1 = "black";
        //         } else {
        //             c1 = "white";
        //         }
        //     }

        //     if (chars[i][0] == coordinate2[0]) {
        //         int rest = i % 2;
        //         int row = coordinate2[1] - '0';  // Convert char to int
        //         if ((rest == 0 && row % 2 == 1) || (rest == 1 && row % 2 == 0)) {
        //             c2 = "black";
        //         } else {
        //             c2 = "white";
        //         }
        //     }
        // }

        // return c1 == c2;


    return ((coordinate1[0] - 'a' + coordinate1[1] - '0') % 2) == ((coordinate2[0] - 'a' + coordinate2[1] - '0') % 2);
    
    // coordinate[0] - 'a': gets column index (0 for 'a', 1 for 'b', etc)
    // coordinate[1] - '0': converts char digit to int ('1' → 1)

    }
};
