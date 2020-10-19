// https://leetcode.com/problems/top-k-frequent-words/submissions/

// Simple use of PQ

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> freq;

        for(auto &w : words)
            ++freq[w];
        
        auto comp = [&](string &x, string &y){
            if(freq[x] == freq[y]) return x > y;
            return freq[x] < freq[y];
        };
            
        priority_queue<string, vector<string>, decltype(comp)> pq(comp);

        for(auto &p : freq)
            pq.push(p.first);
        
        vector<string> ans(k);
        
        for(int i = 0; i < k; ++i){
            ans[i] = pq.top();
            pq.pop();
        }
        
        return ans;
    }
};