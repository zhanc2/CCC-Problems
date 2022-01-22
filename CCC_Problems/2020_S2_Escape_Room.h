//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc20s2

#ifndef CONTEST_PROBLEMS_2020_S2_ESCAPE_ROOM_H
#define CONTEST_PROBLEMS_2020_S2_ESCAPE_ROOM_H

#include <iostream>
#include <vector>

using namespace std;

int getIndex(pair<int, int> a, int n) {
    return (a.first * n) + a.second;
}

void escapeRoom() {
    int m, n;
    cin >> m;
    cin >> n;

    vector<int> room[m];
    map<int, vector<pair<int, int>>> coordinates;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            room[i].push_back(x);
            if (coordinates.find(x) == coordinates.end()) {
                coordinates.insert(pair<int, vector<pair<int, int>>>(x, {{i, j}}));
            } else {
                coordinates[x].push_back({i, j});
            }
        }
    }

    bool vis[m*n];
    for (int i = 0; i < m*n; i++) {
        vis[i] = false;
    }

    queue<pair<int, int>> q;
    q.push({n-1, m-1});

    pair<int, int> current;
    int target;

    while (!q.empty()) {
        current = q.front();
        q.pop();
        target = (current.first+1) * (current.second+1);

        for (auto node : coordinates[target]) {
            int i = getIndex(node, n);
            if (node.first == node.second && node.first == 0) {
                cout << "yes";
                return 0;
            }
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            q.push(node);
        }
    }
    cout << "no";
}

#endif //CONTEST_PROBLEMS_2020_S2_ESCAPE_ROOM_H
