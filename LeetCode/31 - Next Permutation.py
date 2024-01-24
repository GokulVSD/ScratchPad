# https://leetcode.com/problems/next-permutation/description/

# Try swapping the last possible position

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        last = n - 1
        prev = last - 1
        while prev >= 0:
            if nums[prev] < nums[last]:
                tmp = nums[last]
                nums[last] = nums[prev]
                nums[prev] = tmp
                # Reverse remaining list to be lexicographic
                nums[prev + 1:] = nums[prev + 1:][::-1]
                return
            last -= 1
            if prev == last:
                prev -= 1
                last = n - 1
        nums[:] = nums[:][::-1]

