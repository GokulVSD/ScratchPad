// https://leetcode.com/problems/find-and-replace-in-string/submissions/

// Straight forward string handling. Use of STL vector functions like insert
// are super time saving.

class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        
        vector< pair<int, int> > m(indexes.size());
        
        for(int i = 0; i < indexes.size(); ++i)
            m[i] = make_pair(indexes[i], i);
        
        sort(m.begin(), m.end());
        
        string source, target, res = ""; int ind, cur = 0;
        bool match;
        
        for(int i = 0; i < m.size(); ++i){
            
            ind = m[i].first;
            source = sources[m[i].second];
            target = targets[m[i].second];
            
            if(cur < ind)
                res.insert(res.end(), s.begin() + cur, s.begin() + ind);
            
            cur = ind;
            
            match = true;
            for(int j = 0; j < source.size(); ++j){
                if(source[j] != s[ind + j]){
                    match = false;
                    break;
                }
            }
            if(match){
                res.insert(res.end(), target.begin(), target.end());
                cur = ind + source.size();
            } 
        }
        
        if(cur < s.size())
            res.insert(res.end(), s.begin() + cur, s.end());
        
        return res;
    }
};