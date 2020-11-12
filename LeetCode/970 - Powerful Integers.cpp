// https://leetcode.com/problems/powerful-integers/

// Complexity: log(xy)

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        int i = 0, j = 0;
        if (x > 1) while (pow(x, i++) < bound);
		if (y > 1) while (pow(y, j++) < bound);
        
        for (int k = 0; k <= i; k++) {
			for (int l = 0; l <= j; l++) {
				long long int temp = pow(x, k) + pow(y, l);
				if (temp <= bound) s.insert(temp);
			}
		}
        
        vector<int> pint(s.begin(), s.end());
        return pint;
    }
};