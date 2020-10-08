// https://leetcode.com/problems/h-index-ii/submissions/

// Standard binary search. At the end of the binary search, the search space
// starting position (l) will be index of smallest satisfying h

class Solution {
public:
    int hIndex(vector<int>& cit) {
        int mid, l = 0, r = cit.size() - 1;
        while(l <= r){
            mid = (l + r) / 2;
            if(cit[mid] >= cit.size() - mid) r = mid - 1;
            else l = mid + 1;
        }
        return cit.size() - l;
    }
};