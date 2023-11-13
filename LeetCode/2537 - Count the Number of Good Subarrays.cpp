// https://leetcode.com/problems/count-the-number-of-good-subarrays/description/
/*

Sliding window, keep count of frequency of numbers within the window. Every number
that has a frequency 2 or greater, we can do nC2 to get number of pairs.
If this exceeds k, we consider the remaining number of elements to the right of
the window as subarrays that satisfy k, and increment i (adjusting the current
value by -nC2 before decrementing freq of ith, and +nC2 after).

Memoize nC2.

*/

class Solution {
public:
    int memo[100001] = {0};
    int NCR(int n, int r) {
        // if (r == 0) return 1;

        if (memo[n] != 0) {
            return memo[n];
        }

        /*
        Extra computation saving for large R,
        using property:
        N choose R = N choose (N-R)
        */
        if (r > n / 2) {
            memo[n] = NCR(n, n - r);
            return memo[n];
        }
        long res = 1;

        for (int k = 1; k <= r; ++k)
        {
            res *= n - k + 1;
            res /= k;
        }
        memo[n] = res;
        return res;
    }
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long total = 0;
        unordered_map<int, int> m;
        int count = 0;
        int i = 0;
        int j = 1;
        m[nums[i]] = 1;
        int cur = 0;
        while (j < n && i < n - 1) {
            if (cur < j) {
                cur = j;
                if (m.find(nums[j]) != m.end()) {
                    if (m[nums[j]] > 1) {
                        count -= NCR(m[nums[j]], 2);
                    }
                    ++m[nums[j]];
                    if (m[nums[j]] > 1) {
                        count += NCR(m[nums[j]], 2);
                    }
                } else {
                    m[nums[j]] = 1;
                }
            }
            if (count >= k) {
                total += n - j;
                if (m[nums[i]] > 1) {
                    count -= NCR(m[nums[i]], 2);
                }
                --m[nums[i]];
                if (m[nums[i]] > 1) {
                    count += NCR(m[nums[i]], 2);
                }
                ++i;
            } else {
                ++j;
            }
        }
        return total;
    }
};