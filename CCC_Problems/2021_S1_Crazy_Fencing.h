// https://dmoj.ca/problem/ccc21s1

#ifndef CRAZY_FENCING
#define CRAZY_FENCING

#include <iostream>

using namespace std;

int crazyFencing()
{

    int n; cin >> n;
    string heights;
    cin.ignore();
    getline(cin, heights);
    string widths;
    getline(cin, widths);

    long double total = 0.0;

    int height1;
    int height2;
    int width;

    int pos = 0;
    string sub = "";

    for (int i = 0; i < n; i++) {
        pos = heights.find(" ");
        height1 = stoi(heights.substr(0, pos));
        heights.erase(0, pos+1);
        pos = heights.find(" ");
        height2 = stoi(heights.substr(0, pos));
        pos = widths.find(" ");
        width = stoi(widths.substr(0, pos));
        widths.erase(0, pos+1);

        total += min(height1, height2) * width;
        total += float(abs(height1-height2)) * float(width)/2;
    }

    printf("%Lf", total);

    return(0);
}

#endif