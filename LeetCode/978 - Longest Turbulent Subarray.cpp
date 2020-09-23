// https://leetcode.com/problems/longest-turbulent-subarray/

// Faster than 90% of all solutions submitted for the problem

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int max_len = 2, cur_len = 2;
        bool flag = true;
        for(int i = 1; i < A.size() - 1;  ++i){
            if(A[i - 1] > A[i]){
                flag = false;
                if(A[i] < A[i + 1]){
                    ++cur_len;
                    max_len = max(max_len, cur_len);
                }
                else cur_len = 2;
            }
            else if(A[i- 1] < A[i]){
                flag = false;
                if(A[i] > A[i + 1]){
                    ++cur_len;
                    max_len = max(max_len, cur_len);
                }
                else cur_len = 2;
            }
            else{
                cur_len = 2;
            }
        }
        if(flag) --max_len;
        return max_len;
    }
};