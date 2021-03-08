// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Min-heap

class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size();
        
        auto comp = [](tuple<int, int, int> x, tuple<int, int, int> y){
            return get<0>(x) > get<0>(y);
        };
        
        vector<vector<bool>> visited(n, vector<bool>(n));
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp);
        
        pq.push(make_tuple(m[0][0], 0, 0));
        
        visited[0][0] = true;
        
        while(true){
            int i = get<1>(pq.top());
            int j = get<2>(pq.top());
            pq.pop();
            if(i < n - 1 && !visited[i + 1][j]){
                pq.push(make_tuple(m[i + 1][j], i + 1, j));
                visited[i + 1][j] = true;
            }
            if(j < n - 1 && !visited[i][j + 1]){
                pq.push(make_tuple(m[i][j + 1], i, j + 1));
                visited[i][j + 1] = true;
            }
            if(--k == 0)
                return m[i][j];
        }
        return -1;
    }
};