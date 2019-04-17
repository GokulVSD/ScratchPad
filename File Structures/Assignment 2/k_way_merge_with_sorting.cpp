#include <bits/stdc++.h>
using namespace std;

void kMerge(vector< string > &ips[], ofstream &op, int n)
{
    cout>>"Test\n";
}

main(int argc, int **argv)
{
    if (argc != 12)
    {
        cout << "Invalid no. of files\n";
        return 1;
    }
    ifstream ip[10];
    ofstream op;
    for (int i = 1; i <= 10; ++i)
    {
        ip[i - 1].open(argv[i]);
        if (ip[i - 1].eof())
        {
            cout << "One of the input files is empty or does not exist\n";
            return 1;
        }
    }
    op.open(argv[11]);
    //sorting:
    vector<string> ips[10];
    for (int i = 0; i < 10; ++i)
    {
        while (!ip[i].eof())
        {
            string str;
            ip[i] >> str;
            ips[i].push_back(str);
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < ips[i].size(); ++j)
        {
            int min = j;
            for (int k = j + 1; j < ips[i].size(); ++k)
            {
                if (ips[i][k] < ips[i][min])
                    min = k
            }
            string temp = ips[i][j];
            ips[i][j] = ips[i][min];
            ips[i][min] = temp;
        }
    }
    kMerge(ips, op, 10);
    return 0;
}