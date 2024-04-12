//
// Created by 86138 on 2024/4/11.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int mark[10] = {0};
    long long ans = 0;
    mark[2] = mark[0] = mark[1] = mark[9] = 1;
    for (int i = 1; i <= 2019; i++) {
        int x = i;
        while (x) {
            if (mark[x % 10]) {
                ans += i * i;
                break;
            }
            x /= 10;
        }
    }
    cout << ans;
}