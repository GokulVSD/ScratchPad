// https://leetcode.com/problems/longest-palindromic-substring/submissions/

// DP, i should start from end, as we utilise dp[i + 1] for evaluating i

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, length = 0;
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        if (i == j)
          dp[i][j] = true;
        else if (j < i + 3)
          dp[i][j] = s[i] == s[j];
        else
          dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
        if (dp[i][j] && j - i + 1 > length) {
          start = i;
          length = j - i + 1;
        }
      }
    }
    return s.substr(start, length);
  }
};

// Way faster solution:

string longestPalindrome(string s) {
  if (s.size() < 2)
    return s;
  int max_len = 0;
  int start_idx = 0;
  int i = 0;
  while (i < s.size()) {
    int r_ptr = i;
    int l_ptr = i;
    // find the middle of a palindrome
    while (r_ptr < s.size() - 1 && s[r_ptr] == s[r_ptr + 1])
      r_ptr++;
    i = r_ptr + 1;
    // expand from the middle out
    while (r_ptr < s.size() - 1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) {
      r_ptr++;
      l_ptr--;
    }
    int new_len = r_ptr - l_ptr + 1;
    if (new_len > max_len) {
      start_idx = l_ptr;
      max_len = new_len;
    }
  }
  return s.substr(start_idx, max_len);
}
