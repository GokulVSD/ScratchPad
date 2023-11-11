// https://leetcode.com/problems/teemo-attacking/submissions/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int prevEnd = timeSeries[0] + duration - 1;
        int total = duration;
        for (int j = 1; j < timeSeries.size(); ++j) {
            int ticks;
            if (timeSeries[j] - prevEnd > 0) {
                ticks = duration;
            } else {
                ticks = timeSeries[j] - prevEnd - 1 + duration;
            }
            total += ticks;
            prevEnd = timeSeries[j] + duration - 1;
        }
        return total;
    }
};