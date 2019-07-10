// https://www.hackerrank.com/challenges/ctci-array-left-rotation/

vector<int> rotLeft(vector<int> a, int d) {

    int n = a.size();
    vector<int> temp(n);

    for(int i = 0; i < n; ++i)
        temp[(( i - d ) % n + n) % n] = a[i];

    return temp;
}