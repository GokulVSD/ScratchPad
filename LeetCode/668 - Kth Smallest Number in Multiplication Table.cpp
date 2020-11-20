// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/submissions/

/*
The gist behind binary search problems is to ask yourself:

1. Do I know the exact range of possible responses?
2. Can I check quickly enough if a response is correct?
3. Every time I check a response, do I remove all lesser or greater options?

So in this case:
1. Yes. The response is for sure in the range [1, m*n]
2. Yes, I can check it in M time
3. Yes

Often times the trickiest part of these problems is how to check if a certain option is correct fast enough, because the logarithmic reduction of the search part removes almost all the time complexity.

The count function returns the number of numbers in the table that are less than or equal to v.
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int mid, left = 1, right = m*n;
        while(left < right){
            mid = (left + right)/2;
            int cnt = count(mid, m,  n);
            if(cnt >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    int count(int v, int m, int n){
        int c = 0;
	    for(int i = 1; i <= m; ++i)
	        c += min(v/i, n); // row by row, each row differs by a factor of i
	    return c;
    }
};