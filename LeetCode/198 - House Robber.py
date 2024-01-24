# https://leetcode.com/problems/house-robber/description/

class Solution:
    def rob(self, nums: List[int]) -> int:
        # dp[i] = Most money considering first i houses.
        # dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])
        n = len(nums)
        cur = nums[0]
        excl_prev = 0
        for i in range(1, n):
            tmp = cur
            cur = max(nums[i] + excl_prev, cur)
            excl_prev = tmp
        return cur