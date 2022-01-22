//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc00s2

#ifndef CONTEST_PROBLEMS_2000_S2_BABBLING_BROOKS_H
#define CONTEST_PROBLEMS_2000_S2_BABBLING_BROOKS_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void babblingBrooks() {
    int n, river;
    float flowPercent, tempflow;
    cin >> n;
    vector<float> f;
    for (int i = 0; i < n; i++) {
        cin >> tempflow;
        f.push_back(tempflow);
    }
    int input;

    while (true) {
        cin >> input;
        if (input == 77) {
            break;
        } else if (input == 99) {
            cin >> river;
            cin >> flowPercent;
            tempflow = f[river-1];
            f[river-1] = tempflow * (flowPercent/100);
            f.insert(f.begin()+river, (tempflow * (1 - (flowPercent/100))));
        } else {
            cin >> river;
            f[river] = f[river] + f[river-1];
            f.erase(f.begin()+river-1);
        }
    }
    for (int i = 0; i < f.size(); i++) {
        cout << roundf(f[i]) << " ";
}

#endif //CONTEST_PROBLEMS_2000_S2_BABBLING_BROOKS_H
