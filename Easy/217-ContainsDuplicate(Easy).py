import numpy as np

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if (len(np.unique(nums)) != len(nums)):
            return True
        return False
# This is a really bad solution
