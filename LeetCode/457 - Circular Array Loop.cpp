// https://leetcode.com/problems/circular-array-loop/description/

// Do toposort (add all indegree 0 to queue, pop adjust, repeat),
// if we find queue  empty but not all nodes visited, at least one cycle.

// Modifications: only consider same direction and length > 1. This
// means we don't even allow paths in the wrong direction.

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> visited;
        vector<vector<int>> g(n);
        queue<int> q;
        vector<int> deg(n, 0);
        for (int u = 0; u < n; ++u) {
            int v = (n + (u + nums[u]) % n) % n;
            if (u == v || nums[u] * nums[v] < 0) {
                continue;
            }
            ++deg[v];
            g[u].push_back(v);
        }
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited.insert(u);
            for (auto& v : g[u]) {
                --deg[v];
                if (deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return visited.size() != n;
    }
};