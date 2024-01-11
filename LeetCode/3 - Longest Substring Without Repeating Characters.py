# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = {}
        l = 0
        last_repeated = -1
        for i, c in enumerate(s):
            if c in d:
                last_repeated = max(last_repeated, d[c])
            l = max(l, i - last_repeated)
            d[c] = i
        return l