// https://leetcode.com/problems/add-to-array-form-of-integer/submissions/

// As per constraints, K can be max 10^5. Without the constraint, I would compute from back to front, and call reverse() on the result.

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> s(A.size() + 5);
        int carry = 0, acc;
        for(int i = s.size() - 1; i >= 0; --i){
            if(i >= 5)
                acc = A[i - 5] + (K % 10) + carry;
            else
                acc = (K % 10) + carry;
            s[i] = acc % 10;
            carry = acc / 10;
            K /= 10;
        }
        for(int i = 0; i < s.size(); ++i)
            if(s[i] != 0)
                return vector<int>(s.begin() + i, s.end());
        return vector<int>(1);
    }
};