// https://www.hackerrank.com/challenges/sherlock-and-anagrams/

inline bool match(string a, string b){

    for(int l = 0; l < a.length(); ++l)
        if(a[l] != b[l]) return false;

    return true;

}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    int len = s.length();

    vector< vector<string> > m(len);

    for(int i = 1; i <= len; ++i){

        for(int j = 0; j <= len - i; ++j){

            m[i - 1].emplace_back(s.substr(j, i));

        }

    }

    int pairs = 0;


    for(auto i : m){

        for(int j = 0; j < i.size() - 1; ++j){

            string a = i[j];
            sort(a.begin(), a.end());

            for(int k = j + 1; k < i.size(); ++k){
                
                string b = i[k];
                sort(b.begin(), b.end());

                if(match(a,b))
                    ++pairs;

            }

        }

    }

    return pairs;

}