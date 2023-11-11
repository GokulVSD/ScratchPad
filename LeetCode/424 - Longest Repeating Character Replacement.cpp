// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> counts(26, 0);
        int start = 0;
        int maxCount = 0;
        int maxSize = 0;
        for (int end = 0; end < n; ++end) {
            ++counts[s[end] - 'A'];
            maxCount = max(maxCount, counts[s[end] - 'A']);
            // Check if we have used up all K in the window.
            while (end - start - maxCount >= k) {
                --counts[s[start++] - 'A'];
            }
            maxSize = max(maxSize, end - start + 1);
        }
        return maxSize;
    }
};