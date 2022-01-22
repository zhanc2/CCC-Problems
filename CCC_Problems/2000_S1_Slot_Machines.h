//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc00s1

#ifndef CONTEST_PROBLEMS_2000_S1_SLOT_MACHINES_H
#define CONTEST_PROBLEMS_2000_S1_SLOT_MACHINES_H

#include <iostream>

using namespace std;

void slotMachines() {
    int q;
    cin >> q;
    int m1, m2, m3;
    cin >> m1;
    cin >> m2;
    cin >> m3;
    int count = 0;

    for (int i = 0; i < q; i++) {
        if (i % 3 == 0) {
            m1++;
            if (m1 % 35 == 0) {
                q += 30;
            }
        } else if (i % 3 == 1) {
            m2++;
            if (m2 % 100 == 0) {
                q += 60;
            }
        } else {
            m3++;
            if (m3 % 10 == 0) {
                q += 9;
            }
        }
        count++;
    }
    cout << "Martha plays " << count << " times before going broke.";
}

#endif //CONTEST_PROBLEMS_2000_S1_SLOT_MACHINES_H
