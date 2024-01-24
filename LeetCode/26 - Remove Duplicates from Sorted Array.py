# https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 1
        j = 1
        while j < len(nums):
            if nums[i - 1] != nums[j]:
                nums[i] = nums[j]
                i += 1
            j += 1
        return i