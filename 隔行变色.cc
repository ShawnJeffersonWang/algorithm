//
// Created by 86138 on 2024/4/11.
//
#include <bits/stdc++.h>

#define BLUE 0
#define WHITE 1

using namespace std;

int main() {
    int color = BLUE;
    int ans = 0;
    for (int i = 1; i <= 50; i++) {
        if (i >= 21 && color == BLUE) {
            ans++;
        }
//        color ^= 1;
        color = 1 - color;
    }
    cout << ans;
}