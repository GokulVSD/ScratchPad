# https://leetcode.com/problems/roman-to-integer/description/

class Solution:
    def romanToInt(self, s: str) -> int:
        p = {
            'I': 1,
            'IV': 4,
            'V': 5,
            'IX': 9,
            'X': 10,
            'XL': 40,
            'L': 50,
            'XC': 90,
            'C': 100,
            'CD': 400,
            'D': 500,
            'CM': 900,
            'M': 1000,
        }
        i = 0
        n = len(s)
        val = 0
        while i < n:
            if i < n - 1 and s[i : i + 2] in p:
                val += p[s[i : i + 2]]
                i += 2
            else:
                val += p[s[i]]
                i += 1
        return val