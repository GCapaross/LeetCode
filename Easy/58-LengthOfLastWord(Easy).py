class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        cursor = len(s) - 1
        ch = s[cursor]
        l = 0

        while ch == ' ':
            cursor -= 1
            ch = s[cursor]

        while ch != ' ' and cursor > 0:
            l += 1
            cursor -= 1
            ch = s[cursor]

        if ch != ' ':
            l += 1

        return l
