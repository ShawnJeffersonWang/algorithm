//
// Created by shawn on 24-5-29.
//
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        // caabbaaacccaacaa
        vector<int> groups[26];
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            cnt++;
            if (i == n - 1 || s[i] != s[i + 1]) {
                groups[s[i] - 'a'].push_back(cnt);
                cnt = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (groups[i].empty()) {
                continue;
            }
            groups[i].push_back(0);
            groups[i].push_back(0);
            ranges::sort(groups[i], greater());
            ans = max({ans, groups[i][0] - 2,
                       min(groups[i][1], groups[i][0] - 1), groups[i][2]});
        }
        return ans;
    }
};

int main() {
    Solution s;
    auto ans = s.maximumLength("aaaa");
    cout << ans << endl;
}