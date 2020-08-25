#pragma once
#include <vector>

using namespace std;

void rotateClockwise(vector<vector<int>>& A) {
    int n = A.size();
    // transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(A[i][j], A[j][i]);
        }
    }
    // swap rows
    int start = 0, end = n - 1;
    while (start < end)
    {
        for (int i = 0; i < n; i++) {
            swap(A[i][start], A[i][end]);
        }
        start++;
        end--;
    }
}

void rotateCounterClockwise(vector<vector<int>>& A) {
    int n = A.size();
    // transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(A[i][j], A[j][i]);
        }
    }

    // swap columns
    int start = 0, end = n - 1;
    while (start < end)
    {
        for (int i = 0; i < n; i++) {
            swap(A[start][i], A[end][i]);
        }
        start++;
        end--;
    }
}