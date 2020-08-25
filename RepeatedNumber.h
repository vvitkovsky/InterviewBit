#pragma once
#include <vector>

using namespace std;

// 1, 1, 1, 2, 3, 5, 7
int repeatedNumber(const vector<int>& A) {
    int n = A.size();
    int count1 = 0, count2 = 0;
    int first = 0, second = 0;

    for (auto x : A) {

        if (first == x) {
            // if this element is previously seen,  
            // increment count1.
            count1++;
        }
        else if (second == x) {
            // if this element is previously seen,  
            // increment count1.
            count2++;
        }
        else if (count1 == 0) {
            count1++;
            first = x;
        }
        else if (count2 == 0) {
            count2++;
            second = x;
        }
        else {
            // if current element is different from 
            // both the previously seen variables,  
            // decrement both the counts. 
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    // Again traverse the array and find the 
    // actual counts. 
    for (auto x : A) {
        if (x == first) {
            count1++;
        }
        else if (x == second) {
            count2++;
        }
    }

    if (count1 > n / 3)
        return first;

    if (count2 > n / 3)
        return second;

    return -1;
}