// https://leetcode.com/problems/the-k-strongest-values-in-an-array/submissions/

// nth_element performs quickselect to find median. Since output can be in any order, we
// can again do quickselect to put first k strongest at the start of the array. O(n)

// Alternatively, we can use priority queue to pop k elements. O(n + klogn)

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        nth_element(arr.begin(), arr.begin() + (n - 1) / 2, arr.end());
        int m = arr[(n - 1) / 2];
        nth_element(arr.begin(), arr.begin() + k, arr.end(), [&](int a, int b) { 
            return abs(a - m) == abs(b - m) ? a > b : abs(a - m) > abs(b - m); 
        });
        arr.resize(k);
        return arr;
    }
};