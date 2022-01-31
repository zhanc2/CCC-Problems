//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc21s3

#ifndef CONTEST_PROBLEMS_2021_S3_LUNCH_CONCERT_H
#define CONTEST_PROBLEMS_2021_S3_LUNCH_CONCERT_H

#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

ll lunch_concert_get_time(ll concertLocation, int num, vector<ll>& positions, vector<ll>& speeds, vector<ll>& hearings) {
    ll sum = 0;
    for (int i = 0; i < num; i++) {
        ll left = concertLocation - hearings[i];
        ll right = concertLocation + hearings[i];
        if (left < positions[i] && positions[i] < right) {
            continue;
        }
        sum += min(abs(positions[i] - left), abs(positions[i] - right)) * speeds[i];
    }
    return sum;
}

void lunchConcert() {
    int n;
    cin >> n;
    vector<ll> pos(n);
    vector<ll> speed(n);
    vector<ll> hearing(n);
    ll leftBoundary = 1000000000;
    ll rightBoundary = 0;
    for (int i = 0; i < n; i++) {
        cin >> pos[i] >> speed[i] >> hearing[i];
        leftBoundary = min(pos[i], leftBoundary);
        rightBoundary = max(pos[i], rightBoundary);
    }

    ll time;

    ll middle;

    while (leftBoundary <= rightBoundary) {
        middle = (rightBoundary + leftBoundary) / 2;
        time = lunch_concert_get_time(middle, n, pos, speed, hearing);

        if (lunch_concert_get_time(middle - 1, n, pos, speed, hearing) < time) {
            rightBoundary = middle - 1;
        } else if (lunch_concert_get_time(middle + 1, n, pos, speed, hearing) < time) {
            leftBoundary = middle + 1;
        } else {
            break;
        }
    }
    cout << time;
}

#endif //CONTEST_PROBLEMS_2021_S3_LUNCH_CONCERT_H
