#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int mod = 1000003;
int fact(int n) {
    return (n <= 1) ? 1 : (n * fact(n - 1)) % mod;
}

int findRank(string A) {
    int rank = 1;
    for (int i = 0; i < A.size(); i++) {
        int c = 0;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[i] > A[j])
                c++;
        }
        rank = (rank + (c * fact(A.size() - 1 - i)) % mod) % mod;
    }
    return rank;
}

void permute(string str, string out)
{
    // When size of str becomes 0, out has a 
    // permutation (length of out is n) 
    if (str.size() == 0)
    {
        cout << out << endl;
        return;
    }

    // One be one move all characters at 
    // the beginning of out (or result) 
    for (int i = 0; i < str.size(); i++)
    {
        // Remove first character from str and 
        // add it to out 
        permute(str.substr(1), out + str[0]);

        // Rotate string in a way second character 
        // moves to the beginning. 
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

// Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.
int findVals(vector<int>& A, int B, int C) {

    if (!C || !A.size())
        return 0;

    vector<int> num;
    int c = C;
    while (c) {
        num.push_back(c % 10);
        c /= 10;
    }

    // B > C ka size
    if (B > num.size())
        return 0;

    // B < C ka size
    if (B < num.size()) {
        if (B == 1)
            return A.size();

        int x = A.size();
        if (A[0] == 0)
            x--;

        return x * pow(A.size(), B - 1);
    }

    // B == C ka size
    int len = num.size();
    int ans = 0;

    if (len == 1) {
        return (lower_bound(A.begin(), A.end(), C) - A.begin()); // 0 will be considered here
    }
    for (int i = len - 1; i >= 0; i--) {

        int count = lower_bound(A.begin(), A.end(), num[i]) - A.begin(); // number less than MSB

        if (i == len - 1 && A[0] == 0) {
            count--;
        }
        ans += (count * pow(A.size(), i)); //i = remaining length

        // if this number is not found,  example -
        //A : [ 2, 3, 5, 6, 7, 9 ]
        // B : 5
        // C : 42950
        // as 4 is not found, we need to break after 1 iteraion itself
        //for the leftmost digit the numbers possible are either 2 or 3. 
        //And for the rest of the digits, it’s 6^4 as you pointed out, 
        //therefore the total number of possibilities = 2 * 6^4 = 2592
        if (!binary_search(A.begin(), A.end(), num[i]))
            return ans;

    }
    return ans;
}