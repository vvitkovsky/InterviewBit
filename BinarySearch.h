#pragma once

#include <vector>
#include <string>

using namespace std;

int binarySearch(const int* Arr, int n, int target) {

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

int findMedian(vector<vector<int>>& A) {
    int m = A.size();
    int n = A[0].size();

    // median is the middle of a sorted list of numbers. So, median
    // is greater than or equal to half of N + 1 numbers or more 
    // eg. 123 4 567, N = 7, median is greater than or equal 4 numbers
    // So to find the median, we need to find a number that is 
    // greater than or equal to at least half of N + 1 numbers
    int max = A[0][0], min = A[0][0];

    // Let's try to apply binary search to find that mid element
    // Let's find the min and max of the array. Since each row is
    // already sorted, the first element is the smallest and the last
    // element is the biggest in the row. So, we only need to compare
    // the first element of every row to find the smallest element and
    // compare the last element of every row to find the largest
    for (int i = 0; i < m; i++) {
        if (A[i][0] < min) min = A[i][0];
        if (A[i][n - 1] > max) max = A[i][n - 1];
    }

    // mid has to be greater than or equal half the elements
    int required = (m * n + 1) / 2;
    // min <= max will fail when we have the median no. before the mid
    // position to after the mid position
    // eg. 113 3 333, here, initially mid is 2, since its sum < required
    // min becomes 3. max is 3. mid is 3. Since sum > required for 3
    // max is 3. Again mid is 3, again max is 3.. this goes into an 
    // infinite loop. And anyway if the median exists between 3 and 3
    // it means the median is 3!, we can exit the loop and print it
    while (min < max) {

        int sum = 0;
        int mid = (min + max) / 2;
        for (int i = 0; i < m; i++) {
            // Count the number of elements lower than or equal to mid
            // i.e How many numbers is mid greater than or equal to
            // in each row using upper_bound function in STL
            sum += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        // If the element is more than or equal the required no. of elements
        // or more, then it is the median
        // eg. 123 4 567, here, required = 4, mid = 4, 4 has 4 nos. less 
        // than or equal to it, sum == required, therefore 4 is the median
        // So, in both the cases sum > required and sum == required, there is 
        // no guarantee that the element is the median, since it may not exist
        // in the matrix. We can only say that the median may be equal to this
        // element (in case it is present in the matrix) or lesser than this 
        // element (in case it is not present in the matrix) i.e it is the max
        // value the median can be
        // if(sum >= required) return mid;
        if (sum >= required) {
            max = mid;
        }
        // If fewer number of elements are lesser than 
        // or equal to the element, try the next higher one
        else min = mid + 1;
    }
    // return max or min, they are the same since we exited the loop on that condition
    return max;
}

int searchMatrix(vector<vector<int>>& A, int B) {
    for (auto& x : A) {
        int first = *x.begin();
        int last = *x.rbegin();

        if (first == B || last == B) {
            return 1;
        }
        if (first < B && B < last) {
            return binary_search(x.begin(), x.end(), B) ? 1 : 0;
        }
    }
    return 0;
}

bool searchMatrix2(vector<vector<int>>& matrix, int B) {
    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0, r = m * n - 1;
    while (l != r) {
        int mid = (l + r - 1) >> 1;
        if (matrix[mid / m][mid % m] < B)
            l = mid + 1;
        else
            r = mid;
    }
    return matrix[r / m][r % m] == B;
}

vector<int> searchRange(const vector<int>& A, int B) {
    int n = A.size();
    int l = 0;
    int r = n - 1;
    
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (A[mid] == B) {
            l = mid;
            while (l > 0 && A[l - 1] == B) {
                l--;
            }
            r = mid;
            while (r < n - 1 && A[r + 1] == B) {
                r++;
            }          
            return { l, r };            
        }
        else if (B > A[mid]) {
            l = mid + 1;
        }
        else if (B < A[mid]) {
            r = mid - 1;
        }
    }
    return { -1, -1 };
}

int pow(int x, int n, int d) {
    if (n == 0) return 1 % d;

    long long ans = 1, base = x;
    while (n > 0) {
        // We need (base ** n) % d. 
        // Now there are 2 cases. 
        // 1) n is even. Then we can make base = base^2 and n = n / 2.
        // 2) n is odd. So we need base * base^(n-1) 
        if (n % 2 == 1) {
            ans = (ans * base) % d;
            n--;
        }
        else {
            base = (base * base) % d;
            n /= 2;
        }
    }
    if (ans < 0) ans = (ans + d) % d;
    return ans;
}

int search(const vector<int>& A, int B) {
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

    auto r1 = binarySearch(A.data(), index - 1, B);
    auto r2 = binarySearch(A.data() + index, n - index, B);

    if (r2 >= 0) {
        r2 += index;
    }

    return max(r1, r2);
}