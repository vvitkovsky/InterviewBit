// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#include "RotateMatrix.h"
#include "Interval.h"
#include "Matrix.h"
#include "RepeatedNumber.h"
#include "Math.h"
#include "Dividers.h"
#include "Permutation.h"
#include "BinarySearch.h"
#include "Strings.h"

using namespace std;

vector<int> maxset(vector<int>& A) {
    vector<int> result;
    vector<int> tmp;

    long long maxSum = -1;
    long long currentSum = 0;

    for (auto i = 0; i < A.size(); i++) {
        if (A[i] >= 0) {
            tmp.push_back(A[i]);
            currentSum += A[i];
        }
        
        if (A[i] < 0 || i == A.size() - 1) {
            if (currentSum > maxSum) {
                result = tmp;
                maxSum = currentSum;
                currentSum = 0;
                tmp.clear();
            }
        }
    }
    return result;
}

int solve(vector<int>& A) {
    sort(A.begin(), A.end());
    int size = A.size();
    for (int i = 0; i < size; i++) {
        if (i + 1 < size && A[i] == A[i + 1]) {
            continue;
        }
        if (A[i] == size - 1 - i) {
            return 1;
        }
    }
    return -1;
}

vector<int> wave(vector<int>& A) {

    vector<int> result = A;
    sort(result.begin(), result.end());

    for (auto i = 1; i < result.size(); i+=2) {
        int tmp = result[i];
        result[i] = result[i - 1];
        result[i - 1] = tmp;
    }
    return result;
}

string largestNumber(const vector<int>& A) {
    vector<string> vec;
    for (auto x : A) {
        vec.push_back(to_string(x));
    }

    sort(vec.begin(), vec.end(), [] (string a, string b) {
        return a + b > b + a;
    });

    string result;
    for (auto x : vec) {
        result += x;
    }     
    return result;
}

int main()
{    
    auto r = zigZagConcat("PAYPALISHIRING", 3);

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
