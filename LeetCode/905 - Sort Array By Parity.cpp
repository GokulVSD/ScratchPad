// https://leetcode.com/problems/sort-array-by-parity/

// Find evens with j, and sequentially swap from front of the vector.

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        return A;
    }
};