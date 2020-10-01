// https://leetcode.com/problems/path-with-maximum-probability/

// This problem was very time sensetive and hence annoying.

class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        // Graph creation
        vector< vector< pair<double, int> > > graph(n);
        
        for(int i = 0; i < edges.size(); ++i){
            graph[edges[i][0]].emplace_back(make_pair(succProb[i], edges[i][1]));
            graph[edges[i][1]].emplace_back(make_pair(succProb[i], edges[i][0]));
        }
        
        // Djikstra
        priority_queue< pair<double, int> > pq;
        vector<bool> visited(n, false);
                
        for(int i = 0; i < n; ++i)
            pq.push(make_pair(0.0, i));

        pq.push(make_pair(1.0, start));

        while(pq.size() != 0){
            int u = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            
            if(visited[u]) continue;
            visited[u] = true;

            if(u == end) return prob; // Djikstra from start to end only
            
            for(int v = 0; v < graph[u].size(); ++v)
                if(!visited[graph[u][v].second])
                    pq.push(make_pair(prob * graph[u][v].first, graph[u][v].second));
        }
        return 0.0; 
    }
};