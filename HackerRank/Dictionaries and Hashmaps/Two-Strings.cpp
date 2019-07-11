// https://www.hackerrank.com/challenges/two-strings/

string twoStrings(string s1, string s2) {

    bool flag = false;

    for(char c : s1){

        if(s2.find(c) != string::npos)
            flag = true;

    }

    return flag ? "YES" : "NO";

}