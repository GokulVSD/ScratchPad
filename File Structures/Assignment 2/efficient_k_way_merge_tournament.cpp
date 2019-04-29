#include <bits/stdc++.h>
using namespace std;

// Using tournament tree

void kMerge(vector< string > ips[], ofstream &op, int no_of_files){
    int index[no_of_files];
    fill_n(index,no_of_files,1);
    int n = pow(2, ceil(log2(no_of_files)));
    cout << "Starting k-way merge...\n";
    pair< string,int > tree[2*n - 1];
    int i;
    for(int i = n - 1; i < (no_of_files + n - 1); ++i){
        tree[i].first = ips[i - n + 1][0];
        tree[i].second = i - n + 1;
    }
    // Initialising tree
    cout << "Starting tree construction\n";
    i = n - 1;
    int beg = i;
    int end = no_of_files + n - 1;
    while(i != 0){
        if(i + 1 == end || tree[i].first <= tree[i+1].first){
            tree[(int)(ceil(i/2.0) - 1)].first = tree[i].first;
            tree[(int)(ceil(i/2.0) - 1)].second = tree[i].second;
        } else {
            tree[(int)(ceil(i/2.0) - 1)].first = tree[i + 1].first;
            tree[(int)(ceil(i/2.0) - 1)].second = tree[i + 1].second;
        }
        i += 2;
        if(i >= end){
          i = (int)(ceil(beg/2.0) - 1);
          beg = i;
          end = (int)(ceil(end/2.0) - 1);
        }
    }
    cout << "Finished tree construction\n";
    cout << "Running algorithm...\n";
    string lastop = "";
    while(! (tree[0].first).empty()){
        if(!(lastop == tree[0].first))
            op << tree[0].first << "\n";
        lastop = tree[0].first;
        int leaf = n - 1 + tree[0].second;
        tree[leaf].first = ips[tree[0].second][index[tree[0].second]++];
        while(leaf != 0){
            if(leaf % 2 == 0) --leaf;
            if((tree[leaf].first).empty() && (tree[leaf + 1].first).empty()){
                tree[(int)(ceil(leaf/2.0) - 1)].first = "\0";
            }
            else if((tree[leaf+1].first).empty() || tree[leaf].first <= tree[leaf + 1].first){
                tree[(int)(ceil(leaf/2.0) - 1)].first = tree[leaf].first;
                tree[(int)(ceil(leaf/2.0) - 1)].second = tree[leaf].second;
            } else{
                tree[(int)(ceil(leaf/2.0) - 1)].first = tree[leaf + 1].first;
                tree[(int)(ceil(leaf/2.0) - 1)].second = tree[leaf + 1].second;
            }
            leaf = (int)(ceil(leaf/2.0) - 1);
        }
    }
    op.close();
    cout << "Done\n";
}

int main(int argc, char **argv){
    argc -= 1;
    if (argc < 3){
        cout << "Invalid no. of files\n";
        return 1;
    }
    ifstream ip[argc-1];
    ofstream op;
    for (int i = 1; i <= argc-1; ++i){
        ip[i - 1].open(argv[i]);
        if (ip[i - 1].peek() == -1){
            cout << "One of the input files is empty or does not exist\n";
            return 1;
        }
    }
    op.open(argv[argc]);
    // Sorting:
    cout << "Sorting...\n";
    vector<string> ips[argc-1];
    for (int i = 0; i < argc-1; ++i){
        while (!ip[i].eof()){
            string str;
            ip[i] >> str;
            ips[i].push_back(str);
        }
        ips[i].pop_back();
    }
    for (int i = 0; i < argc-1; ++i){
        for (int j = 0; j < ips[i].size() - 1; ++j){
            int min = j;
            for (int k = j + 1; k < ips[i].size(); ++k){
                if (ips[i][k] < ips[i][min])
                    min = k;
            }
            string temp = ips[i][j];
            ips[i][j] = ips[i][min];
            ips[i][min] = temp;
        }
    }
    cout << "Done sorting\n";
    kMerge(ips, op, argc-1);
    return 0;
}
