l = [None for i in range(46)]

class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1

        if n == 2:
            return 2

        if l[n] is None:
            l[n] = self.climbStairs(n-1) + self.climbStairs(n-2)
        
        return l[n]
