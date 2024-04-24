class Solution:
    def mySqrt(self, x: int) -> int:
       if x == 0:
            return 0
       elif x == 1:
            return 1
       for i in range(int(x)+ 1):
        if i*i > x:
            return int(i-1)
