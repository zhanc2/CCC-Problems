//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc21s3

#ifndef CONTEST_PROBLEMS_2021_S3_LUNCH_CONCERT_H
#define CONTEST_PROBLEMS_2021_S3_LUNCH_CONCERT_H

#include <iostream>
#include <vector>

using namespace std;

long long lunch_concert_get_time(int pos, int num, vector<int>& positions, vector<int>& speeds, vector<int>& hearings) {
    long long sum = 0;
    for (int i = 0; i < num; i++) {
        sum += ((long long)abs(positions[i] - pos) - hearings[i]) * speeds[i];
    }
    return sum;
}

void lunchConcert() {
    int n;
    cin >> n;
    vector<int> pos(n);
    vector<int> speed(n);
    vector<int> hearing(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i] >> speed[i] >> hearing[i];
    }

    long long boundary_1 = 0;
    long long boundary_2;

    if (n > 2000) {
        boundary_2 = 2000;
    }
    else {
        boundary_2 = 1000000000;
    }

    int count = 0;

    long long time;

    int middle;

    long long previous;

    while (true) {
        middle = (boundary_2 - boundary_1) / 2;
        time = lunch_concert_get_time(middle, n, pos, speed, hearing);

        if (count != 0) {
            if (time < previous) {

            }
        }
        else {
            previous = time;
        }

        count++;
        if (count > 100) {
            break;
        }
    }
}

#endif //CONTEST_PROBLEMS_2021_S3_LUNCH_CONCERT_H
