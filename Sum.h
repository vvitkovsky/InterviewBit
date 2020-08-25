#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int solve2(vector<string>& A) {
    if (A.size() < 3) return 0;

    float a = stof(A[0]);
    float b = stof(A[1]);
    float c = stof(A[2]);

    for (int i = 3; i < A.size(); ++i) {
        float sum = a + b + c;
        if (sum > 1 && sum < 2)
            return 1;

        float temp = stof(A[i]);

        if (sum >= 2) {
            if (a > b && a > c)
                a = temp;
            else if (b > c && b > a)
                b = temp;
            else
                c = temp;
        }
        else {
            if (a < b && a < c)
                a = temp;
            else if (b < c && b < a)
                b = temp;
            else
                c = temp;
        }
    }

    float sum = a + b + c;
    if (sum > 1 && sum < 2) return 1;
    return 0;
}

int solve(vector<string>& A) {
    if (A.size() < 3) return 0;

    vector<double> vec;
    for (auto x : A) {
        vec.push_back(stod(x));
    }

    double a = vec[0];
    double b = vec[1];
    double c = vec[2];

    priority_queue<double, vector<double>, greater<double>> pq(vec.begin() + 3, vec.end());

    while (!pq.empty())
    {
        double sum = a + b + c;
        if (sum > 1 && sum < 2)
            return 1;

        float next = pq.top();
        pq.pop();

        double sum1 = next + a + b;
        if (1 < sum1 && sum1 < 2) {
            return 1;
        }

        double sum2 = next + b + c;
        if (1 < sum2 && sum2 < 2) {
            return 1;
        }

        double sum3 = next + a + c;
        if (1 < sum3 && sum3 < 2) {
            return 1;
        }

        if (sum >= 2) {
            if (a > b && a > c)
                a = next;
            else if (b > c && b > a)
                b = next;
            else
                c = next;
        }
        else {
            if (a < b && a < c)
                a = next;
            else if (b < c && b < a)
                b = next;
            else
                c = next;
        }
    }

    float sum = a + b + c;
    if (sum > 1 && sum < 2) return 1;
    return 0;
}