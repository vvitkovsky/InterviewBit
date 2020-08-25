#pragma once
#include <vector>
#include <queue>

using namespace std;

int firstMissingPositive(vector<int>& A) {
    priority_queue<int, std::vector<int>, std::greater<int>> pq(A.begin(), A.end());
    int i = 1;
    while (!pq.empty()) {
        int val = pq.top();
        pq.pop();

        if (val == i) {
            i++;
        }
        else if (val > i) {
            break;
        }
    }
    return i;
}

int firstMissingPositive2(vector<int>& A) {
    int c = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 1) {
            c = 1;
        }
        if (A[i] <= 0 || A[i] > A.size()) {
            A[i] = 1;
        }
    }

    if (c == 0) {
        return 1;
    }

    for (int i = 0; i < A.size(); i++) {
        A[abs(A[i]) - 1] = -abs(A[abs(A[i]) - 1]);
    }

    for (int i = 0; i < A.size(); i++) {
        if (A[i] > 0) {
            return i + 1;
        }
    }
    return A.size() + 1;
}