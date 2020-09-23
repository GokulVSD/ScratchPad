// https://leetcode.com/problems/valid-square/

// Initially made the mistake of assuming the square can only be rectiliniear. On a side note, the way the code was input was very tedious to tackle.

class Solution {
public:
    
    inline int dist(vector<int>& p1, vector<int>& p2){
        return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
    } 
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        unordered_map<int, int> dist_count;
        int dist1 = dist(p1, p2), dist2;
        
        ++dist_count[dist1];
        
        if(dist(p1, p3) != dist1) dist2 = dist(p1, p3);
        ++dist_count[dist(p1, p3)];
        
        if(dist(p1, p4) != dist1) dist2 = dist(p1, p4);
        ++dist_count[dist(p1, p4)];
        
        if(dist(p2, p3) != dist1) dist2 = dist(p2, p3);
        ++dist_count[dist(p2, p3)];
        
        if(dist(p2, p4) != dist1) dist2 = dist(p2, p4);
        ++dist_count[dist(p2, p4)];
        
        if(dist(p3, p4) != dist1) dist2 = dist(p3, p4);
        ++dist_count[dist(p3, p4)];
        
        if(dist_count[dist1] == 4 && dist_count[dist2] == 2) return true;
        if(dist_count[dist2] == 4 && dist_count[dist1] == 2) return true;
        
        return false;
        
    }
};