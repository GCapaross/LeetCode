class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        return 1 if abs(x-z) < abs(y-z) else 2 if abs(y-z) < abs(x-z) else 0
        
