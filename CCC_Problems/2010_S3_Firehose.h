//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc10s3

#ifndef CONTEST_PROBLEMS_2010_S3_FIREHOSE_H
#define CONTEST_PROBLEMS_2010_S3_FIREHOSE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_dis(int a, int b) {
    return (max(a, b) - min(a, b) + 1000000) % 1000000;
}

int solveHouseConfig(int hose_len, vector<int>& houses) {
    int hydrant_count = 0;
    int hydrant_index;
    int dis;

    for (int i = 0; i < (int)houses.size(); i++) {
        hydrant_index = houses[i] + hose_len;
        hydrant_count++;
        for (int j = i + 1; j < (int)houses.size(); j++) {
            dis = abs(get_dis(hydrant_index, houses[j]));
            if (dis > hose_len) {
                i += j - i - 1;
                break;
            }
            if (j == ((int)houses.size() - 1)) {
                i = (int)houses.size();
                break;
            }
        }

    }

    return hydrant_count;
}

void fireHose() {
    int H;
    cin >> H;
    vector<int> houses(H, 0);
    for (int i = 0; i < H; i++) {
        cin >> houses[i];
    }
    sort(houses.begin(), houses.end());
    int k;
    cin >> k;
    if (k >= H) {
        cout << "0";
        return;
    }

    pair<int, int> max_dis = { 0, 0 };
    for (int i = 0; i < H - 1; i++) {
        if (houses[i + 1] - houses[i] > max_dis.first) {
            max_dis.first = houses[i + 1] - houses[i];
            max_dis.second = i;
        }
    }

    vector<int> linear_houses(H);
    int count = 0;
    int max_dis_index = (max_dis.second + 1) % H;
    int offset = houses[max_dis_index];

    while (count < H) {
        linear_houses[count] = (houses[max_dis_index] - offset + 1000000) % 1000000;
        count++;
        cout << houses[max_dis_index] << endl;
        max_dis_index = (max_dis_index + 1) % H;
    }
    cout << endl;

    int hose_length = 0;
    int hydrant_count = 0;
    int first = 0;
    int last = 500000;
    int smallest = 500000;
    bool x = false;
    int z = 0;

    while (true) {
        if (z > 15) {
            break;
        }
        hose_length = (int)((first + last) / 2);
        hydrant_count = solveHouseConfig(hose_length, linear_houses);
        if (hydrant_count == k) {
            last = hose_length - 1;
            if (smallest > hose_length) {
                smallest = hose_length;
                x = true;
            }
        }
        else {
            if (hydrant_count < k) {
                last = hose_length - 1;
            }
            else if (hydrant_count > k) {
                first = hose_length + 1;
                if (x) {
                    z++;
                }
            }
        }
    }

    cout << smallest;
}

#endif //CONTEST_PROBLEMS_2010_S3_FIREHOSE_H
