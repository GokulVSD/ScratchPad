// https://www.hackerrank.com/challenges/sock-merchant/

int sockMerchant(int n, vector<int> ar) {

    int arr[101];
    fill_n(arr, 101, 0);
    int count = 0;

    for(auto &i : ar){

        if(++arr[i] & 1){
            continue;
        }
        else{
            arr[i] = 0;
            ++count;
        }
    }
    
    return count;
}