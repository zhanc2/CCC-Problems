//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc18s3

#ifndef CONTEST_PROBLEMS_2018_S3_ROBO_THIEVES_H
#define CONTEST_PROBLEMS_2018_S3_ROBO_THIEVES_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

pair<int, int> get_end_con(vector<vector<char>> room, char starting_dir, pair<int, int> starting_pos) {
    char dir = starting_dir;
    char room_content;
    int pos_1 = starting_pos.first;
    int pos_2 = starting_pos.second;
    vector<vector<bool>> vis(room.size(), vector<bool>(room[0].size()));
    vis[pos_1][pos_2] = true;
    while (true) {
        if (dir == 'U') {
            pos_1 -= 1;
        }
        else if (dir == 'D') {
            pos_1 += 1;
        }
        else if (dir == 'L') {
            pos_2 -= 1;
        }
        else {
            pos_2 += 1;
        }
        if (vis[pos_1][pos_2]) {
            return { -1, -1 };
        }
        vis[pos_1][pos_2] = true;
        room_content = room[pos_1][pos_2];
        if (room_content == 'U') {
            dir = 'U';
        }
        else if (room_content == 'D') {
            dir = 'D';
        }
        else if (room_content == 'L') {
            dir = 'L';
        }
        else if (room_content == 'R') {
            dir = 'R';
        }
        else {
            return { pos_1, pos_2 };
        }
    }
}

void roboThieves() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> room(n, vector<char>(m));
    string c;
    vector<pair<int, int>> empty_cells;
    pair<int, int> start_coords;
    vector<vector<bool>> in_cam_sight(n, vector<bool>(m));
    vector<vector<bool>> cam_pos(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> c;
        for (int j = 0; j < m; j++) {
            room[i][j] = c[j];
            if (c[j] == 'S') {
                start_coords = { i, j };
                continue;
            }
            if (c[j] == '.') {
                empty_cells.push_back({ i, j });
                continue;
            }
            if (c[j] == 'C') {
                cam_pos[i][j] = true;
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cam_pos[i][j]) {
                in_cam_sight[i][j] = true;
                for (int z = i - 1; z > -1; z--) {
                    char a = room[z][j];
                    if (a == '.') {
                        in_cam_sight[z][j] = true;
                        continue;
                    }
                    if (a == 'W') {
                        break;
                    }
                    if (a == 'S') {
                        for (auto x : empty_cells) {
                            cout << -1 << endl;
                        }
                        return;
                    }
                }
                for (int z = i + 1; z < n; z++) {
                    char a = room[z][j];
                    if (a == '.') {
                        in_cam_sight[z][j] = true;
                        continue;
                    }
                    if (a == 'W') {
                        break;
                    }
                    if (a == 'S') {
                        for (auto x : empty_cells) {
                            cout << -1 << endl;
                        }
                        return;
                    }
                }
                for (int z = j - 1; z > -1; z--) {
                    char a = room[i][z];
                    if (a == '.') {
                        in_cam_sight[i][z] = true;
                        continue;
                    }
                    if (a == 'W') {
                        break;
                    }
                    if (a == 'S') {
                        for (auto x : empty_cells) {
                            cout << -1 << endl;
                        }
                        return;
                    }
                }
                for (int z = j + 1; z < m; z++) {
                    char a = room[i][z];
                    if (a == '.') {
                        in_cam_sight[i][z] = true;
                        continue;
                    }
                    if (a == 'W') {
                        break;
                    }
                    if (a == 'S') {
                        for (auto x : empty_cells) {
                            cout << -1 << endl;
                        }
                        return;
                    }
                }
            }
        }
    }

    vector<vector<int>> dis(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push(start_coords);
    vis[start_coords.first][start_coords.second] = true;
    pair<int, int> adjacent[4];

    while (!q.empty()) {
        int f = q.front().first;
        int s = q.front().second;

        q.pop();

        adjacent[0] = { f - 1, s };
        adjacent[1] = { f + 1, s };
        adjacent[2] = { f, s - 1 };
        adjacent[3] = { f, s + 1 };

        for (auto coord : adjacent) {
            int n_1 = coord.first;
            int m_1 = coord.second;
            char room_content = room[n_1][m_1];
            if (room_content != 'W') {
                if (room_content == 'U') {
                    pair<int, int> c = get_end_con(room, 'U', { n_1, m_1 });
                    if (c.first == -1 && c.second == -1) {
                        continue;
                    }
                    if (!vis[c.first][c.second] && !in_cam_sight[c.first][c.second] && room[c.first][c.second] != 'W') {
                        dis[c.first][c.second] = dis[f][s] + 1;
                        vis[c.first][c.second] = true;
                        q.push(c);
                    }
                }
                else if (room_content == 'D') {
                    pair<int, int> c = get_end_con(room, 'D', { n_1, m_1 });
                    if (c.first == -1 && c.second == -1) {
                        continue;
                    }
                    if (!vis[c.first][c.second] && !in_cam_sight[c.first][c.second] && room[c.first][c.second] != 'W') {
                        dis[c.first][c.second] = dis[f][s] + 1;
                        vis[c.first][c.second] = true;
                        q.push(c);
                    }
                }
                else if (room_content == 'L') {
                    pair<int, int> c = get_end_con(room, 'L', { n_1, m_1 });
                    if (c.first == -1 && c.second == -1) {
                        continue;
                    }
                    if (!vis[c.first][c.second] && !in_cam_sight[c.first][c.second] && room[c.first][c.second] != 'W') {
                        dis[c.first][c.second] = dis[f][s] + 1;
                        vis[c.first][c.second] = true;
                        q.push(c);
                    }
                }
                else if (room_content == 'R') {
                    pair<int, int> c = get_end_con(room, 'R', { n_1, m_1 });
                    if (c.first == -1 && c.second == -1) {
                        continue;
                    }
                    if (!vis[c.first][c.second] && !in_cam_sight[c.first][c.second] && room[c.first][c.second] != 'W') {
                        dis[c.first][c.second] = dis[f][s] + 1;
                        vis[c.first][c.second] = true;
                        q.push(c);
                    }
                }
                else {
                    if (!in_cam_sight[n_1][m_1]) {
                        if (!vis[n_1][m_1]) {
                            vis[n_1][m_1] = true;
                            dis[n_1][m_1] = dis[f][s] + 1;
                            q.push({ n_1, m_1 });
                        }
                    }
                }
            }
        }
    }

    for (auto i : empty_cells) {
        if (dis[i.first][i.second] > 0) {
            cout << dis[i.first][i.second] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}

#endif //CONTEST_PROBLEMS_2018_S3_ROBO_THIEVES_H
