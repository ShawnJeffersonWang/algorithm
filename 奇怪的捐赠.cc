//
// Created by 86138 on 2024/4/11.
//
//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//#define maxn 100
const int maxn = 100;

int main() {
    int p[maxn];
    p[0] = 1;
    for (int i = 1; i < maxn; i++) {
        p[i] = p[i - 1] * 7;
    }
    int n = 1000000;
    int ans = 0;
    while (n) {
        int x = n % 7;
        ans += x;
        if (x == 6) {
            printf("sb");
        }
        n /= 7;
    }
    printf("%d\n", ans);
}