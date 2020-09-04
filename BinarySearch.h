#pragma once

#include <vector>
#include <string>

using namespace std;

int binarySearch(int* Arr, int n, int target) {

	//set stating and ending index
	int start = 0, end = n - 1;

	while (start <= end) {
		// take mid of the list
		int mid = (start + end) / 2;
		// we found a match
		if (Arr[mid] == target) {
			return mid;
		}
		// go on right side
		else if (Arr[mid] < target) {
			start = mid + 1;
		}
		// go on left side
		else {
			end = mid - 1;
		}
	}
	// element is not present in list
	return -1;
}

int findCount(const vector<int>& A, int B) {
    int l = 0, h = A.size() - 1;
    int r = 0;

    while (l <= h) {

        int mid = (h + l) / 2;        
		if (A[mid] < B) {
            l = mid + 1;
        }
        else if (A[mid] > B) {
            h = mid - 1;
        }
        else {
			int c = mid;
            while (c <= h && A[c] == B) {
                r++;
                c++;
            }
			c = mid - 1;
			while (c >= l && A[c] == B) {
				r++;
				c--;
			}
            break;
        }
    }
    return r;
}

int findCount2(const vector<int>& A, int B) {
	return upper_bound(A.begin(), A.end(), B) - lower_bound(A.begin(), A.end(), B);
}

int findMin(const vector<int>& A) {
    int n = A.size();
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        // pivot should be less then next and previous
        if (A[mid] <= A[mid + 1] && A[mid] <= A[mid - 1]) {
            return A[mid];
        }
        if (A[mid] <= A[h]) {
            // right side is sorted
            h = mid - 1;
        }
        else if (A[mid] >= A[l]) {
            // left side is sorted
            l = mid + 1;
        }
    }
    return A[l];
}

int findMin2(const vector<int>& A) {
    int n = A.size();
    int low = 0, high = n - 1; 
    int index = 0; //index of a small number
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] < A[index]) {
            //as the array sorted search on left until finding small number
            index = mid;
            high = mid - 1;
        }
        else { 
            //else search on right
            low = mid + 1; 
        }
    }
    return A[index]; //return small number
}

int sqrt(int A) {
    if (A < 2) {
        return A;
    }
    int l = 1, h = A / 2;
    int r = 0;
    while (l <= h) {
        long long mid = (h + l) / 2;
        long long val = mid * mid;
        if (val == A) {
            return mid;
        }
        else if (val < A) {
            r = mid;
            l = mid + 1;
        }
        else if (val > A) {
            if (r != 0) {
                break;
            }
            h = mid - 1;
        }
    }
    return r;
}