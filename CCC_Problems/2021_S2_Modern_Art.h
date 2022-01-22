#ifndef MODERN_ART
#define MODERN_ART

#include <iostream>
#include <vector>

using namespace std;

int modernArt()
{
    int h, w, moves, pos;
    cin >> h;
    cin >> w;
    cin >> moves;

    vector<vector<int> > board(h, vector<int>(w));
    vector<int> r(h, 0);
    vector<int> c(w, 0);

    string move;

    for (int i = 0; i < moves; i++) {
        cin >> move >> pos;

        if (move == "R") {
            r[pos-1]++;
        } else {
            c[pos-1]++;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            board[i][j] = r[i];
        }
    }

    int total = 0;

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            board[j][i] += c[i];
            if (board[j][i] % 2 == 1) {
                total++;
            }
        }
    }
    cout << total;
    return 0;
}

#endif