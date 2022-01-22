//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc15s2

#ifndef CONTEST_PROBLEMS_2015_S2_JERSEYS_H
#define CONTEST_PROBLEMS_2015_S2_JERSEYS_H

#include <iostream>

using namespace std;

void jerseyRequests() {
    int j, a, pNum;
    char J[1000000], pSize;
    int count = 0;
    cin >> j;
    cin >> a;
    for (int i = 0; i < j; i++) {
        cin >> J[i];
    }
    for (int i = 0; i < a; i++) {
        cin >> pSize >> pNum;
        pNum--;
        if (J[pNum] != 'Z') {
            if (abs(J[pNum] - 'L') < 8) {
                if (J[pNum] <= pSize) {
                    count++;
                    J[pNum] = 'Z';
                }
            }
        }
    }
    cout << count;
}

#endif //CONTEST_PROBLEMS_2015_S2_JERSEYS_H
