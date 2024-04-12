//
// Created by shawn on 24-4-12.
//
#include <bits/stdc++.h>

using namespace std;

int day[] = {
        -1,
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
};

int isLeapYear(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return 1;
    }
    return 0;
}

int has2(int x) {
    while (x) {
        if (x % 10 == 2) {
            return 1;
        }
        x /= 10;
    }
    return 0;
}

int main() {
    int cnt = 0;
    for (int y = 1900; y <= 9999; y++) {
        for (int m = 1; m <= 12; m++) {
            int day_max = day[m];
            if (m == 2) {
                day_max += isLeapYear(y);
            }
            for (int d = 1; d <= day_max; d++) {
                if (has2(y) || has2(m) || has2(d)) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}