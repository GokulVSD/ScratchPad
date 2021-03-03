// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/submissions/

// Using a bitmap, checking upto 26 characters for each char in s, better approach using sliding window and count of variables below

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string, int> freq;
        int max_freq = 0;
        for(int i = 0; i < n; ++i){
            int bitmap = 0;
            int unique = 0;
            for(int j = i; j < min(i + maxSize, n); ++j){
                if(!(bitmap & (1 << (s[j] - 'a')))){
                    ++unique;
                    bitmap |= (1 << (s[j] - 'a'));

                }
                if(unique > maxLetters)
                    break;
                if(j - i >= minSize - 1){
                    string tmp = s.substr(i, j - i + 1);
                    ++freq[tmp];
                    max_freq = max(max_freq, freq[tmp]);
                }
            }            
        }
        return max_freq;
    }
};

// We can ignore maxSize, as whatever substring upto minSize will be contained upto maxSize too, and we are looking to count max number of substrings, which will obviously be a smaller substring
int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
{
    int start=0,result=0;
    unordered_map<int,int> count;           	//Stores count of letters in the window.
    unordered_map<string,int> occurence;        //Stores count of occurence of that string.
    for(int i=0;i<s.length();i++)			//Sliding window
    {
        count[s[i]]++;						//Increase the count of letter at i.
        if(i-start+1>minSize)                  //Reduce the size of the window if increased to size.
        {
            if(--count[s[start]]==0)			//Remove the letter from map if count 0 to track unique letters.
                count.erase(s[start]);
            start++;
        }
        if(i-start+1==minSize&&count.size()<=maxLetters)	//When the substring in the window matches the constraints.
            result=max(result,++occurence[s.substr(start,i-start+1)]); //Increase the occurence count of the string and get the max.
    }
    return result;
}