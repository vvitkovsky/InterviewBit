#pragma once

#include <vector>
#include <unordered_map>

using namespace std;
/*
You are given an array of arrays a. Your task is to group the arrays a[i] by their mean values, so that arrays with equal mean values are in the same group, and arrays with different mean values are in different groups.
Each group should contain a set of indices (i, j, etc), such that the corresponding arrays (a[i], a[j], etc) all have the same mean. Return the set of groups as an array of arrays, where the indices within each group are sorted in ascending order, and the groups are sorted in ascending order of their minimum element.
*/

vector<vector<int>> meanGroups(vector<vector<int>> input) {
    vector<vector<int>> r;
    unordered_map<int, int> indexes;

    for (int i = 0; i < input.size(); i++) {
        int mean = 0;
        for (int j = 0; j < input[i].size(); j++) {
            mean += input[i][j];
        }
        mean /= input[i].size();

        auto itr = indexes.find(mean);
        if (itr == indexes.end()) {
            r.push_back({ i });
            indexes[mean] = r.size() - 1;
        }
        else {
            r[itr->second].push_back(i);
        }
    }
    return r;
}

