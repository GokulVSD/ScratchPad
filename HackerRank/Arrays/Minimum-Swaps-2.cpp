// https://www.hackerrank.com/challenges/minimum-swaps-2/

int minimumSwaps(vector<int> arr) {

    int l = 0, r = arr.size() - 1, swaps = 0, tmp;

    while (l < r) {

        while (arr[l] == l + 1 && l < r)
            ++l;

        if (l < r) {
            tmp = arr[ arr[l] - 1 ];
            arr[ arr[l] - 1 ] = arr[l];
            arr[ l ] = tmp;
            ++swaps;
        }

    }

    return swaps;

}