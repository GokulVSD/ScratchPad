// https://leetcode.com/problems/top-k-frequent-elements/

// Priority Queue (heap) with constructor initialisation, as constructing priority queue is O(n)
// as opposed to pushing to priority queue O(nlogn)

// Another interesting solution using buckets of frequency: https://leetcode.com/problems/top-k-frequent-elements/discuss/81602/Java-O(n)-Solution-Bucket-Sort

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res(k);
        vector<pair<int, int>> freq; 
        unordered_map<int, int> m;
        for(auto &n : nums){
            ++m[n];
        }
        for(auto &p: m){
            freq.emplace_back(make_pair(p.first, p.second));
        }
        auto comp = [](pair<int, int> x, pair<int, int> y){
            return x.second < y.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(m.begin(), m.end(), comp);
        for(int i = 0; i < k; ++i){
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};