// https://leetcode.com/problems/redundant-connection/solution/

// Using Disjoint Set Union data structure

class Solution {
public:
    
    unordered_map<int, int> parent, rank;
    
    // DSU find with path compression
    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    // DSU union with rank
    bool dsu_union(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) {
            return false;
        } else if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
        } else if (rank[xr] > rank[yr]) {
            parent[yr] = xr;
        } else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 1; i <= edges.size(); ++i){
            parent[i] = i;
        }
        for(auto &e : edges){
            if(!dsu_union(e[0], e[1])) return e;
        }
        return edges[0];
    }
};