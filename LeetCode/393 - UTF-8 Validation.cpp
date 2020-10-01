// https://leetcode.com/problems/utf-8-validation/

// I need to be more careful with accounting for all conditions.

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int ind = 0;
        while(ind < data.size()){
            int no_of_bytes = -2; 
            int bit = 1;
            int byte = 128;
            while(bit){
                bit = data[ind] & byte;
                byte = byte >> 1;
                ++no_of_bytes;
                if(byte < 1) return false;
            }
            if(no_of_bytes == 0) return false;
            no_of_bytes = max(no_of_bytes, 0);
            if(no_of_bytes > 3) return false;
            while(no_of_bytes--){
                ++ind;
                if(ind >= data.size()) return false;
                if(128 & data[ind] && 64 ^ data[ind]) continue;
                return false;
            }
            ++ind;
        }
        return true;
    }
};