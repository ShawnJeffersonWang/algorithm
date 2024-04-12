//
// Created by shawn on 24-4-12.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        int pre = 1000;
        while (x) {
            if (x % 10 > pre) {
                break;
            }
            pre = x % 10;
            x /= 10;
        }
        if (x == 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}