//
// Created by Charles Zhang on 2021-12-28.
//
// https://dmoj.ca/problem/ccc19s2

#ifndef CONTEST_PROBLEMS_2019_S2_PRETTY_AVERAGE_PRIMES_H
#define CONTEST_PROBLEMS_2019_S2_PRETTY_AVERAGE_PRIMES_H

#include <iostream>

using namespace std;

int primes[2000001] = { 0 };

bool is_prime(int x) {
    if (x == 1) { return false; }
    if (x == 2) { return true; }

    for (int i = 2; i * i <= x; i++) {
        if (primes[i - 1] > 0) {
            if (x % i == 0) {
                primes[x - 1] = -x;
                return false;
            }
        }
        if (primes[i - 1] < 0) {
            continue;
        }
        if (primes[i - 1] == 0) {
            if (is_prime(i)) {
                if (x % i == 0) {
                    primes[x - 1] = -x;
                    return false;
                }
            }
            else {
                continue;
            }
        }
    }

    primes[x - 1] = x;
    return true;
}

void prettyAveragePrimes() {
    int num_prime; cin >> num_prime;
    int num;
    int pairs[1001][2];

    for (int i = 0; i < num_prime; i++) {
        cin >> num;
        for (int j = 2; j < num; j++) {
            if (is_prime(j)) {
                if (is_prime((2 * num) - j)) {
                    pairs[i][0] = j;
                    pairs[i][1] = (2 * num) - j;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < num_prime; i++) {
        cout << pairs[i][0] << " " << pairs[i][1] << endl;
    }
}

#endif //CONTEST_PROBLEMS_2019_S2_PRETTY_AVERAGE_PRIMES_H
