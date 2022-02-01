//
// Created by Charles Zhang on 2022-01-31.
//
// https://dmoj.ca/problem/ccc17s3

#ifndef CONTEST_PROBLEMS_2017_S3_NAILED_IT_H
#define CONTEST_PROBLEMS_2017_S3_NAILED_IT_H

#include <iostream>
#include <map>

using namespace std;

void nailedIt() {
    int boardsNum;
    cin >> boardsNum;

    map<int, int> boardFrequency;
    int largestBoard = 0;

    for (int i = 0; i < boardsNum; i++) {
        int b;
        cin >> b;
        boardFrequency[b]++;
        largestBoard = max(b, largestBoard);
    }

    int maxHeight = 0;

    map<int, int> possibilities;

    int currentMax;
    for (int targetHeight = 2; targetHeight <= largestBoard*2; targetHeight++) {
        currentMax = 0;
        for (auto b : boardFrequency) {
            if (targetHeight < b.first) {
                break;
            }
            if (b.first*2 < targetHeight) {
                int secondBoard = targetHeight - b.first;
                currentMax += min(b.second, boardFrequency[secondBoard]);
            } else if (b.first*2 == targetHeight) {
                currentMax += b.second/2;
            }
        }
        if (currentMax > maxHeight) {
            maxHeight = currentMax;
            possibilities[currentMax] = 1;
        } else if (currentMax == maxHeight && maxHeight != 0) {
            possibilities[currentMax]++;
        }
    }

    cout << maxHeight << " " << possibilities[maxHeight];
}

#endif //CONTEST_PROBLEMS_2017_S3_NAILED_IT_H
