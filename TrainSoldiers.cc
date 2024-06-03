//
// Created by shawn on 24-4-27.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, S;
    vector<int> p;
    vector<int> c;
    cin >> N >> S;
    int n = N;
    while (n--) {
        int pi, ci;
        cin >> pi >> ci;
        p.push_back(pi);
        c.push_back(ci);
    }
    int sum = 0;
    while (true) {
        int flag = 1;
        int consume = 0;
        for (int i = 0; i < c.size(); i++) {
            if (c[i] > 0) {
                consume += p[i];
                c[i]--;
                flag = 0;
            }
        }
        sum += min(consume, S);
        if (flag) break;
    }
    cout << sum;
}