# https://leetcode.com/problems/two-sum/description/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, num in enumerate(nums):
            d[num] = i
        for i, num in enumerate(nums):
            if target - num in d and d[target - num] != i:
                return [i, d[target - num]]
