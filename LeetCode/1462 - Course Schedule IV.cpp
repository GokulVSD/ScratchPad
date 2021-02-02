// https://leetcode.com/problems/course-schedule-iv/

// Floyd Warshall reachability (DP on connectivity), can also do DFS memoization

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> connected(n, vector<bool>(n));
        for(auto &p: prerequisites)
            connected[p[0]][p[1]] = true;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    connected[i][j] = connected[i][j] || connected[i][k] && connected[k][j];
        vector<bool> ans;
        for(auto &q: queries)
            ans.emplace_back(connected[q[0]][q[1]]);
        return ans;
    }
};