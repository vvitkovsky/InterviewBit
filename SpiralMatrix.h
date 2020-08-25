#pragma once
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int A) {
    vector<vector<int>> res(A, vector<int>(A, 0));

    int i = 1;
    int dir = 0; // 0 - left, 1 - down, 2 - right, 3 - up 
    int l = 0;
    int r = A - 1;
    int t = 0;
    int b = A - 1;
    while (i <= A * A) {
        if (dir == 0) {
            for (int j = l; j <= r; j++) {
                res[t][j] = i;
                i++;
            }
            t++;
        }
        else if (dir == 1) {
            for (int j = t; j <= b; j++) {
                res[j][r] = i;
                i++;
            }
            r--;
        }
        else if (dir == 2) {
            for (int j = r; j >= l; j--) {
                res[b][j] = i;
                i++;
            }
            b--;
        }
        else {
            for (int j = b; j >= t; j--) {
                res[j][l] = i;
                i++;
            }
            l++;
        }

        if (++dir > 3) {
            dir = 0;
        }
    }
    return res;
}