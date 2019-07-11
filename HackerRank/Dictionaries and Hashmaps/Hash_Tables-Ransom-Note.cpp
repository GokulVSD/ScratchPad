// https://www.hackerrank.com/challenges/ctci-ransom-note/

void checkMagazine(vector<string> magazine, vector<string> note) {

    unordered_map<string, int> m;
    m.reserve(30000);

    for(auto &i : magazine)
        ++m[i];

    for(auto &i : note){

        if(m[i] == 0){

            cout << "No\n";
            return;

        }
        --m[i];

    }

    cout << "Yes\n";
}