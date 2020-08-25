#pragma once
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> result;
    Interval a = newInterval;

    bool added = false;
    for (auto& x : intervals) {
        if (x.end < a.start) {
            result.push_back(x);
            continue;
        }

        if (a.end < x.start) {
            if (!added) {
                result.push_back(a);
                added = true;
            }
            result.push_back(x);
        }

        if (x.start <= a.end && a.start <= x.end) {
            a.start = min(x.start, a.start);
            a.end = max(x.end, a.end);
            continue;
        }
    }

    if (!added) {
        result.push_back(a);
    }
    return result;
}

vector<Interval> merge(vector<Interval>& A) {
    sort(A.begin(), A.end(), [](const Interval& l, const Interval& r)->bool {
        return l.start < r.start;
        });

    if (A.empty()) {
        return A;
    }

    vector<Interval> result;
    Interval last = *A.begin();
    for (int i = 1; i < A.size(); i++) {
        if (A[i].start <= last.end && last.start <= A[i].end) {
            last.start = min(A[i].start, last.start);
            last.end = max(A[i].end, last.end);
            continue;
        }

        result.push_back(last);
        last = A[i];
    }

    result.push_back(last);
    return result;
}