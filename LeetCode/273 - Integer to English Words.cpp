// https://leetcode.com/problems/integer-to-english-words/submissions/

// Consider % 1000 chunks at a time

class Solution {
public:
  string ones[20] = {"Zero",    "One",     "Two",       "Three",    "Four",
                     "Five",    "Six",     "Seven",     "Eight",    "Nine",
                     "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                     "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

  string tens[10] = {"",      "",      "Twenty",  "Thirty", "Forty",
                     "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  string triplets[4] = {"", "Thousand", "Million", "Billion"};

  string triplet(int n) {
    string s;
    int tmp = n % 100;
    if (tmp < 20)
      s = ones[tmp];
    else {
      if (tmp % 10 != 0)
        s = " " + ones[tmp % 10];
      tmp /= 10;
      s = tens[tmp] + s;
    }
    n /= 100;
    if (n > 0) {
      if (tmp == 0)
        s = ones[n] + " Hundred";
      else
        s = ones[n] + " Hundred " + s;
    }
    return s;
  }

  string numberToWords(int num) {
    string ans = "";
    int count = 1;
    do {
      int n = num % 1000;
      num /= 1000;
      string tmp = triplet(n) + ans;
      if (num != 0) {
        if (n == 0)
          tmp = ans;
        if (num % 1000 != 0)
          ans = " " + triplets[count] + (tmp.size() == 0 ? "" : " ") + tmp;
        else
          ans = tmp;
      } else
        ans = tmp;
      ++count;
    } while (num != 0);
    return ans;
  }
};