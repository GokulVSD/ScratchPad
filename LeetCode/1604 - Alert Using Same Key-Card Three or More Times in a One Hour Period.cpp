// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/

// Convert time to int format, and sort

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        vector<string> names;
        for(int i = 0; i < keyName.size(); ++i){
            string t = keyTime[i];
            int mins = stoi(t.substr(0, 2))*60 + stoi(t.substr(3));
            m[keyName[i]].emplace_back(mins);
        }
        for(auto &p : m){
            sort(p.second.begin(), p.second.end());
            int oldest = 0;
            for(int i = 1; i < p.second.size(); ++i){
                if(p.second[i] - p.second[oldest] > 60)
                    ++oldest;
                if(i - oldest + 1 == 3){
                    names.emplace_back(p.first);
                    break;
                }
            }
        }
        sort(names.begin(), names.end());
        return names;
    }
};