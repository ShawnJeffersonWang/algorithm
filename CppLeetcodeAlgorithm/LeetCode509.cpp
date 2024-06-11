#include <bits/stdc++.h>
using namespace std;
// 费波纳契数
// 动态规划解法
class Solution1 {
   public:
    int fib(int n) {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// 动态规划优化
class Solution2 {
   public:
    int fib(int n) {
        if (n <= 1)
            return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
// 递归解法
class Solution3 {
   public:
    int fib(int n) {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};