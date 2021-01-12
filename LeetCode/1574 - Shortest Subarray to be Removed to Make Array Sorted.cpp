// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/submissions/

// comments included

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int j;
		//find last non sorted element
        for (j = arr.size() - 1; j > 0; --j)
            if (arr[j - 1] > arr[j])
                break;
        
        //already sorted
        if (j == 0) return 0;
        
        int res = j;
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0 && arr[i - 1] > arr[i]) break;
            // incase suffix starts with lesser than prefix
            while (j < arr.size() && arr[i] > arr[j])
                ++j;
            res = min(res, j - i - 1);
        }
        return res;
    }
};