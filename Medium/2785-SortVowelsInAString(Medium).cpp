class Solution:
    def sortVowels(self, s: str) -> str:
        vw = sorted(c for c in s if c in 'AEIOUaeiou')[::-1]
        return ''.join(c in 'AEIOUaeiou' and vw.pop() or c for c in s)
