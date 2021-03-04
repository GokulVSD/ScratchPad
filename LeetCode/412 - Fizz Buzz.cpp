// https://leetcode.com/problems/fizz-buzz/

// LOL

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
       for(int i = 1; i <= n; ++i){
           if(i % 3 == 0)
               ans[i - 1] = "Fizz";
           if(i % 5 == 0)
               ans[i - 1] += "Buzz";
           if(ans[i - 1] == "")
               ans[i - 1] = to_string(i);
       }
        return ans;
    }
};