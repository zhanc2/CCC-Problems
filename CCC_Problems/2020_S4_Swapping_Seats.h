//
// Created by Charles Zhang on 2022-01-12.
//
// https://dmoj.ca/problem/ccc20s4

#ifndef CONTEST_PROBLEMS_2020_S4_SWAPPING_SEATS_H
#define CONTEST_PROBLEMS_2020_S4_SWAPPING_SEATS_H

#include <iostream>

using namespace std;

void swappingSeats() {
    string seats;
    int sizeString;
    int frequency[3] = {0};
    cin >> seats;
    sizeString = seats.size();
    if (sizeString == 1) {
        cout << '0';
        return 0;
    }

    int windowA[3] = {0, 0, 0};
    int windowBFirst[3] = {0, 0, 0};
    int windowBSecond[3] = {0, 0, 0};
    int windowCSecond[3] = {0, 0, 0};
    int windowCFirst[3] = {0, 0, 0};

    for (char a : seats) {
        frequency[(int)a - 65]++;
    }

    for (int i = 0; i < sizeString; i++) {
        int c = (int)seats[i] - 65;
        if (i < frequency[0]) {
            windowA[c]++;
            continue;
        }
        if (i < frequency[0] + frequency[1]) {
            windowBFirst[c]++;
        }
        if (i < frequency[0] + frequency[2]) {
            windowCFirst[c]++;
        }
        if (i >= frequency[0] + frequency[1]) {
            windowCSecond[c]++;
        }
        if (i >= frequency[0] + frequency[2]) {
            windowBSecond[c]++;
        }
    }

    int minMoves = min(max(windowBFirst[2], windowCSecond[1]), max(windowBSecond[2], windowCFirst[1])) + windowA[1] + windowA[2];

    for (int i = 0; i < sizeString; i++) {
        int aStart = i;
        int aEnd = i + frequency[0];
        int bStartFirst = aEnd;
        int bEndFirst = bStartFirst + frequency[1];
        int cStartSecond = bEndFirst;
        int cEndSecond = cStartSecond + frequency[2];
        int cStartFirst = aEnd;
        int cEndFirst = cStartFirst + frequency[2];
        int bStartSecond = cEndFirst;
        int bEndSecond = bStartSecond + frequency[1];


        windowA[(int)seats[aStart] - 65]--;
        windowBFirst[(int)seats[bStartFirst % sizeString] - 65]--;
        windowCSecond[(int)seats[cStartSecond % sizeString] - 65]--;
        windowCFirst[(int)seats[cStartFirst % sizeString] - 65]--;
        windowBSecond[(int)seats[bStartSecond % sizeString] - 65]--;

        windowA[(int)seats[aEnd % sizeString] - 65]++;
        windowBFirst[(int)seats[bEndFirst % sizeString] - 65]++;
        windowCSecond[(int)seats[cEndSecond % sizeString] - 65]++;
        windowCFirst[(int)seats[cEndFirst % sizeString] - 65]++;
        windowBSecond[(int)seats[bEndSecond % sizeString] - 65]++;

        if (min(max(windowBFirst[2], windowCSecond[1]), max(windowBSecond[2], windowCFirst[1])) + windowA[1] + windowA[2] < minMoves) {
            minMoves = min(max(windowBFirst[2], windowCSecond[1]), max(windowBSecond[2], windowCFirst[1])) + windowA[1] + windowA[2];
        }
    }

    cout << minMoves;
}

#endif //CONTEST_PROBLEMS_2020_S4_SWAPPING_SEATS_H
