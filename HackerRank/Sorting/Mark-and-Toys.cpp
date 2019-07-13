// https://www.hackerrank.com/challenges/mark-and-toys/

int maximumToys(vector<int> prices, int k) {

    sort(prices.begin(), prices.end());

    int maxtoys = 0;

    for(auto i : prices){

        k -= i;

        if(k < 0) break;

        ++maxtoys;

    }

    return maxtoys;

}
