// https://leetcode.com/problems/rectangle-overlap/solution/

// Consider overlapping one axis at a time. If both axis overlap, then rectangle overlaps.

class Solution {
 public:
    bool isRectangleOverlap(vector<int> rec1, vector<int> rec2) {
        return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) && // width > 0
                min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));  // height > 0
    }
};