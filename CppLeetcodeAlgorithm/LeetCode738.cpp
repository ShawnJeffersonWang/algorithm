#include <bits/stdc++.h>
using namespace std;
// 单调递增的数字
// 暴力解法
class Solution1 {
   private:
    bool checkNum(int num) {
        int max = 10;
        while (num) {
            int t = num % 10;
            num /= 10;
            if (max >= t)
                max = t;
            else
                return false;
        }
        return true;
    }

   public:
    int monotoneIncreasingDigits(int n) {
        for (int i = n; i > 0; i--) {
            if (checkNum(i))
                return i;
        }
        return 0;
    }
};
// 贪心解法
class Solution2 {
   public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i]) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};