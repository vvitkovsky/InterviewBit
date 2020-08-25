#pragma once
#include <vector>
#include <algorithm>

using namespace std;

vector<int> repeatedMissedNumber(const vector<int>& A) {
    int r = 0;
    int m = 0;

    vector<int> ans = A;
    for (int i = 0; i < A.size(); i++) {
        
        int x = abs(ans[i]) - 1;
        ans[x] = -ans[x];

        if (ans[x] > 0) {
            r = abs(ans[i]);
            // change sign back
            ans[x] = -ans[x];
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] > 0) {
            m = i + 1;
            break;
        }
    }

    return { r, m };
}

vector<int> repeatedMissedNumber(const vector<int>& A) {
    long sum = 0, sumSq = 0;
    for (int i : A)
    {
        sum += i;
        sumSq += ((long)i) * i;
    }

    long n = A.size();
    // sum
    long dsum = n * (n + 1) / 2;
    // sum of squares
    long dsumSq = n * (n + 1) * (2 * n + 1) / 6;
    // dif sum
    long d1 = sum - dsum;
    // dif sum of squares
    long d2 = sumSq - dsumSq;
    // dif divided
    long eq = d2 / d1;

    long repeat = (eq + d1) / 2;
    long miss = (eq - d1) / 2;

    return { (int)repeat,(int)miss };
}