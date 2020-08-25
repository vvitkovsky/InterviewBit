#pragma once

#include <vector>
#include <set>

using namespace std;

void setZeroes(vector<vector<int> >& A) {
    set<int> rows;
    set<int> cols;
    for (auto i = 0; i < A.size(); i++) {
        for (auto j = 0; j < A[i].size(); j++) {
            if (A[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for (auto x : rows) {
        for (auto i = 0; i < A[0].size(); i++) {
            A[x][i] = 0;
        }
    }

    for (auto x : cols) {
        for (auto i = 0; i < A.size(); i++) {
            A[i][x] = 0;
        }
    }
}

void setZeroes2(vector<vector<int> >& A) {

    bool fillZeroRow = false;
    for (auto i = 0; i < A[0].size(); i++) {
        if (A[0][i] == 0) {
            fillZeroRow = true;
            break;
        }
    }

    bool fillZeroCol = false;
    for (auto i = 0; i < A.size(); i++) {
        if (A[i][0] == 0) {
            fillZeroCol = true;
            break;
        }
    }

    for (auto i = 0; i < A.size(); i++) {
        for (auto j = 0; j < A[i].size(); j++) {
            if (A[i][j] == 0) {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }

    for (auto i = 1; i < A.size(); i++) {
        for (auto j = 1; j < A[i].size(); j++) {
            if (A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }

    if (fillZeroRow) {
        for (auto i = 0; i < A[0].size(); i++) {
            A[0][i] = 0;
        }
    }

    if (fillZeroCol) {
        for (auto i = 0; i < A.size(); i++) {
            A[i][0] = 0;
        }
    }
}