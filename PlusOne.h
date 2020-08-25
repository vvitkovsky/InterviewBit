#pragma once
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& A) {

    vector<int> result = A;

    if (!result.empty()) {
        int i = result.size() - 1;
        int num = ++result[i];
        while (num > 9 && i >= 0) {
            result[i] = 0;
            i--;
            num = ++result[i];
        }
    }

    for (auto itr = result.begin(); itr != result.end();) {
        if (*itr == 0) {
            itr = result.erase(itr);
            continue;
        }
        break;
    }

    return result;
}