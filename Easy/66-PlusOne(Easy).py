class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:

        num_str = ''.join(map(str, digits))

        incremented_num_str = str(int(num_str) + 1)

        result = [int(digit) for digit in incremented_num_str]

        return result
