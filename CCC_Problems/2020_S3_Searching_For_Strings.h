//
// Created by Charles Zhang on 2022-01-01.
//
// https://dmoj.ca/problem/ccc20s3

#ifndef CONTEST_PROBLEMS_2020_S3_SEARCHING_FOR_STRINGS_H
#define CONTEST_PROBLEMS_2020_S3_SEARCHING_FOR_STRINGS_H

#include <iostream>
#include <map>
#include <set>

using namespace std;

const unsigned primeBase = 227;
const unsigned primeMod = 1000000007;

int hashString(const string& s) {
    int r = 0;
    for (char c : s) {
        r = r * primeBase + c;
        r = r % primeMod;
    }
    return r;
}

void searchForStrings() {
    string n, h;
    cin >> n;
    cin >> h;
    int needleSize = (int)n.size();
    int haySize = (int)h.size();
    if (needleSize > haySize) {
        cout << 0;
        return 0;
    }

    map<int, int> needleMap;
    for (char i : n) {
        int num = (int)i;
        needleMap[num]++;
    }

    set<int> permutations;
    int permutationCount = 0;
    map<int, int> window;

    for (int i = 0; i < needleSize; i++) {
        int c = (int)h[i];
        window[c]++;
    }
    if (window == needleMap) {
        int hashed = hashString(h.substr(0, needleSize));
        if (permutations.find(hashed) == permutations.end()) {
            permutations.insert(hashed);
            permutationCount++;
        }
    }

    for (int i = 0; i < haySize - needleSize + 1; i++) {
        int first = (int)h[i];
        int next = (int)h[i+needleSize];
        window[next]++;
        window[first]--;
        if (window[first] == 0) {
            window.erase(first);
        }
        if (window == needleMap) {
            int hashed = hashString(h.substr(i+1, needleSize));
            if (permutations.find(hashed) == permutations.end()) {
                permutations.insert(hashed);
                permutationCount++;
            }
        }
    }

    cout << permutationCount;
}

#endif //CONTEST_PROBLEMS_2020_S3_SEARCHING_FOR_STRINGS_H
