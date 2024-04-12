//
// Created by shawn on 24-3-7.
//
//本题思路：按位比较两端，如果是大于小于的情况容易处理，但如果是等于的情况需要耗费n的时间复杂度向中间再比较
//这样会使得时间复杂度达到n^3，根据测试用例大小可知后面60%跑不了，需要优化到n^2
//因此启用动态规划，当比较两端大小相等时，如i,j位,直接根据已经计算过的dp[i+1][j-1]得出结论，时间复杂度为1
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    int len = s.size();
    if (len == 1)cout << 0;//如果只有一位直接返回，后续步骤只考虑大于一位情况
    else {
        vector<vector<int>> dp(len, vector<int>(len));
        //二维dp数组含义：dp[i][j]表示i位到j位的子串交换后能否变小，能为1，不能则默认值为0
        //单个字符的字符串交换以后不满足条件，默认为0
        int mid = len / 2;
        int l = mid - 1, r = mid + 1;
        //思路：从中间向两端dp动态规划，这样才能在遍历i，j位时直到dp[i+1][j-1]的值
        while (l >= 0)//先向左遍历
        {
            for (int i = l + 1; i < r; i++) {
                if (i - l == 1)//如果子串只有两位情况单独考虑，因为此时运用dp[i+1][j-1]会出错
                {
                    if (s[i] < s[l]) {
                        ans++;
                        dp[l][i] = 1;
                    }
                } else {
                    if (s[i] < s[l] || (s[i] == s[l] && dp[l + 1][i - 1] == 1)) {
                        ans++;
                        dp[l][i] = 1;
                    }
                }
            }
            l--;
        }
        while (r < len)//再向右遍历
        {
            for (int i = r - 1; i >= 0; i--)//注意是i>=0，完全遍历一个不漏
            {
                if (r - i == 1) {
                    if (s[r] < s[i]) {
                        ans++;
                        dp[i][r] = 1;
                    }
                } else {
                    if (s[r] < s[i] || (s[i] == s[r] && dp[i + 1][r - 1] == 1)) {
                        ans++;
                        dp[i][r] = 1;
                    }
                }
            }
            r++;
        }
        cout << ans;
    }
    return 0;
}