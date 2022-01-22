//
// Created by Charles Zhang on 2021-12-28.
//

#ifndef CONTEST_PROBLEMS_2019_S1_FLIPPER_H
#define CONTEST_PROBLEMS_2019_S1_FLIPPER_H

#include <iostream>

using namespace std;

void flipper() {
    int nums[2][2] = { {1,2}, {3,4} };
    int temp[2] = {};
    string moves; cin >> moves;
    bool last = true;

    for (int i = 0; i < moves.length()-1; i++) {
        if (moves[i] == moves[i + 1]) {
            i++;
            if (i == moves.length() - 1) {
                last = false;
            }
        }
        else if (moves[i] == 'H') {
            temp[0] = nums[0][0]; temp[1] = nums[0][1];
            nums[0][0] = nums[1][0]; nums[0][1] = nums[1][1];
            nums[1][0] = temp[0]; nums[1][1] = temp[1];
        }
        else {
            temp[0] = nums[0][0]; temp[1] = nums[1][0];
            nums[0][0] = nums[0][1]; nums[1][0] = nums[1][1];
            nums[0][1] = temp[0]; nums[1][1] = temp[1];
        }
    }
    if (last) {
        if (moves[moves.length() - 1] == 'H') {
            temp[0] = nums[0][0]; temp[1] = nums[0][1];
            nums[0][0] = nums[1][0]; nums[0][1] = nums[1][1];
            nums[1][0] = temp[0]; nums[1][1] = temp[1];
        }
        else {
            temp[0] = nums[0][0]; temp[1] = nums[1][0];
            nums[0][0] = nums[0][1]; nums[1][0] = nums[1][1];
            nums[0][1] = temp[0]; nums[1][1] = temp[1];
        }
    }
    cout << nums[0][0] << " " << nums[0][1] << endl;
    cout << nums[1][0] << " " << nums[1][1] << endl;
}

#endif //CONTEST_PROBLEMS_2019_S1_FLIPPER_H
