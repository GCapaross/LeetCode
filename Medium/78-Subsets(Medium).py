class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        if len(nums) == 0:
            return [[]]
        elif len(nums) == 1:
            return [[], nums]


        return self.recursive(nums)


    def recursive(self,nums):
        yield []
        for i in range(len(nums)):
            for subset in self.recursive(nums[i+1:]):
                yield [nums[i]] + subset
