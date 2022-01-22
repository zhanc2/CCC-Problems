//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc15s3

#ifndef CONTEST_PROBLEMS_2015_S3_GATES_H
#define CONTEST_PROBLEMS_2015_S3_GATES_H

#include <iostream>
#include <set>

using namespace std;

void planeGateDocking() {
    int plane_count, gate_count, plane_dock;
    cin >> gate_count;
    cin >> plane_count;
    set<int, greater<>> gates;
    for (int i = 0; i < gate_count; i++) {
        gates.insert(i);
    }


    bool going = true;
    int park_count = 0;

    for (int i = 0; i < plane_count; i++) {
        cin >> plane_dock;
        plane_dock--;
        if (going) {
            auto gateEnd = gates.end();
            if (gates.begin() != gateEnd) {
                --gateEnd;
                if (plane_dock < *gateEnd) {
                    going = false;
                    continue;
                }
            }
            auto nextGate = gates.lower_bound(plane_dock);
            if (nextGate == gates.end()) {
                going = false;
                continue;
            }
            gates.erase(nextGate);
            park_count++;
        }
    }
    cout << park_count;
}

#endif //CONTEST_PROBLEMS_2015_S3_GATES_H
