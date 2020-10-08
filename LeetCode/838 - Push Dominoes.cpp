// https://leetcode.com/problems/push-dominoes/

// use of insert(pos, count, char) was very useful. This problem was tedious at first,
// but when i broke it down, I was able to simplify the code.
// Faster than 99%, the code is a lot simpler than the best solution

class Solution {
public:
    string pushDominoes(string dom) {
        string res = "";
        bool R = false;
        for(int i = 0; i < dom.size(); ++i){
            if(dom[i] == 'L'){
                int len = i - res.size();
                if(R){
                    res.insert(res.end(), len/2, 'R');
                    if(len % 2) res += '.';
                    R = false;
                    len /= 2;
                } 
                res.insert(res.end(), len + 1, 'L');
            }
            else if(dom[i] == 'R'){
                if(R)
                    res.insert(res.end(), i - res.size(), 'R');
                else
                    res.insert(res.end(), i - res.size(), '.');
                
                res.insert(res.end(), 'R');
                R = true;
            }
        }
        if(R)
            res.insert(res.end(), dom.size() - res.size(), 'R');
        else
            res.insert(res.end(), dom.size() - res.size(), '.');
        
        return res;
    }
};