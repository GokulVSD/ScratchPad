// https://leetcode.com/problems/remove-k-digits/

// I enjoyed figuring this one out. The trick is to scan from the left as long as the digits keep getting bigger, and delete the digit when it doesn't. Repeat k times.
// Ain't very fast because string erase function is slow, but the complexity is O(k*num.length())

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k == num.length()) return "0";
                
        while(k-- > 0){
            bool none_erased = true;
            for(int i = 0; i < num.length() - 1; ++i){
                if(num[i] > num[i + 1]){
                    num.erase(i, 1);
                    none_erased = false;
                    break;
                }
            }
            if(none_erased) num.erase(num.length() - 1, 1);
        }
        
        // remove leading zeroes after erasing
        int i = -1;
        while(num[++i] == '0' &&  i < num.length() - 1);
        return num.substr(i);
    }
};