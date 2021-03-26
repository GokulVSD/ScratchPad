// https://leetcode.com/problems/maximum-repeating-substring/

// O(n*k), in worst case, k = n, => O(n^2)

class Solution {
public:
    int maxRepeating(string sequence, string word) {
		int k = 0;
		string temp = word;
		while(sequence.find(temp) != string::npos){
			temp += word;
			k++;
		}

		return k;
    }
};