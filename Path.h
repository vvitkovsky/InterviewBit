#pragma once

#include <vector>
#include <algorithm>

using namespace std;

// Grid Unique Paths
int uniquePaths(int A, int B) {
    if (A == 1 || B == 1) {
        return 1;
    }
    return uniquePaths(A - 1, B) + uniquePaths(A, B - 1);
}

long long ma = 1000000007;
long long fact(long long k) {
    if (k == 0)
        return 1;
    else return ((k * fact(k - 1)) % ma);

}
long long power(long long p, long long t) {
    if (t == 0)
        return 1;
    long long y = power(p, t / 2);
    y = (y * y) % ma;
    if (t % 2 == 1)
        y = (y * p) % ma;
    return y;
}

// City Tour
int cityTour(int a, vector<int>& b) {
    int n = b.size();
    sort(b.begin(), b.end());
    long long y = a - n;
    if (y == 0)
        return 0;
    long long ans = fact(y);
    long long q = fact(b[0] - 1);
    for (int i = 0; i < n - 1; i++) {
        long long u = b[i + 1] - b[i] - 1;
        ans = (ans * power(2, u - 1)) % ma;
        q = (q * fact(u)) % ma;
    }
    q = (q * fact(a - b[n - 1])) % ma;
    q = power(q, ma - 2);
    ans = (ans * q) % ma;
    return ans;
}