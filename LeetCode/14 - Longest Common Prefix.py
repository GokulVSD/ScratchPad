# https://leetcode.com/problems/longest-common-prefix/description/

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        pref = strs[0]
        for s in strs:
            i = 0
            while i < len(s) and i < len(pref):
                if pref[i] == s[i]:
                    i += 1
                else:
                    break
            pref = pref[:i]
        return pref