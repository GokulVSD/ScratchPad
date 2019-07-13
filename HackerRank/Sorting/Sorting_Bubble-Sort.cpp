// https://www.hackerrank.com/challenges/ctci-bubble-sort/

inline void swap(int* x, int* y){

    int temp = *x;
    *x = *y;
    *y = temp;

}

void countSwaps(vector<int> a) {

    int nswaps = 0;

    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a.size() - 1; ++j){
            if(a[j] > a[j + 1]){
                ++nswaps;
                swap(a[j], a[j+1]);
            }
        }
    }

    cout << "Array is sorted in " << nswaps << " swaps.\n";
    cout << "First Element: " << a[0] << "\n";
    cout << "Last Element: " << a[a.size() - 1] << "\n";

}