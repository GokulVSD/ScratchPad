// https://leetcode.com/problems/minimum-genetic-mutation/

// BFS solution, better to generate possible mutations from a position, and check their existence using an unordered set, rather than to scan the entire bank. Depends on the problem though, if bank is smaller than number of possible mutuations, might be better to just scan the bank.

// In a problem, if you are unable to generate all possible mutations due to there being too many, you can keep a seen set, and only add to queue if a node hasn't been seen, and it can be branched to, then mark it as seen.

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset;
        bool endvalid = false;
        
        for(auto &g: bank){
            if(end == g)
                endvalid = true;//check if end exists
            bankset.insert(g);
        }
        if(!endvalid)
            return -1;
        
        queue<string> q;
        q.push(start);
        
        int level = 0;
        
        while(!q.empty()){
            ++level;
            int remainingInThisLevel = q.size();
            while(remainingInThisLevel--){
                string cur = q.front();
                q.pop();
                for(int i = 0; i < cur.size(); ++i){
                    string temp = cur;
                    for(char c: "ACGT"){
                        temp[i] = c;
                        if(cur == temp)
                            continue;
                        if(temp == end)
                            return level;
                        if(bankset.find(temp) != bankset.end()){
                            q.push(temp);
                            bankset.erase(temp);
                        }
                    }
                }
            }
        }
        return -1;
    }
};