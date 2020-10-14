// https://leetcode.com/problems/split-two-strings-to-make-palindrome/

// Greedy solution, split only when no longer a palindrome

class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j])
            ++i, --j;
        return i >= j;
    }
    bool check(string &a, string &b) {
        int i = 0, j = a.size() - 1;
        while (i < j && a[i] == b[j])
            ++i, --j;
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};