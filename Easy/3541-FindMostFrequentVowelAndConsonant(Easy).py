class Solution:
    def maxFreqSum(self, s:str)->int:
        return sum(max(((c in'aeiou')^q)*s.count(c)for c in s)for q in(0,1))
