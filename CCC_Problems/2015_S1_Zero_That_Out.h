//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc15s1

#ifndef CONTEST_PROBLEMS_2015_S1_ZERO_THAT_OUT_H
#define CONTEST_PROBLEMS_2015_S1_ZERO_THAT_OUT_H

#include <iostream>
#include <vector>

using namespace std;

void zeroThatOut() {
    int k; cin >> k;
    int total = 0;
    int current;
    vector<int> past;

    for (int i = 0; i < k; i++) {
        cin >> current;
        if (current == 0) {
            total -= past.back();
            past.pop_back();
        }
        else {
            past.push_back(current);
            total += current;
        }
    }
    cout << total;
}

#endif //CONTEST_PROBLEMS_2015_S1_ZERO_THAT_OUT_H
