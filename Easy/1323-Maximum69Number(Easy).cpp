class Solution {
public:
    int maximum69Number (int num) {
        string numb = to_string(num);
        for (char &c : numb) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(numb);
    }
};
