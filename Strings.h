#pragma once

#include <string>
#include <sstream>

using namespace std;

int isPalindrome(string A) {
    int n = A.size();
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        while (l < r && !isalnum(A[l])) l++;
        while (l < r && !isalnum(A[r])) r--;
        if (toupper(A[l]) != toupper(A[r])) return 0;
        l++;
        r--;
    }
    return 1;
}

string longestCommonPrefix(vector<string>& A) {
    size_t maxLength = 0;
    for (auto& x : A) {
        maxLength = max(maxLength, x.size());
    }

    string r;
    for (int i = 0; i < maxLength; i++) {
        char c = A[0][i];
        for (int j = 1; j < A.size(); j++) {
            if (c != A[j][i]) {
                return r;
            }
        }
        r.push_back(c);
    }
    return r;
}

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(string pat, int M, vector<int> lps) {
    // length of the previous longest prefix suffix 
    int len = 0;
    // lps[0] is always 0 
    lps[0] = 0;
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len]) 
        {
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment 
                // i here 
            }
            else // if (len == 0) 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> kmpSearch(string pat, string txt, bool onlyFirst = false)
{
    // result positions
    vector<int> r;

    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    vector<int> lps(M, 0);

    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            // Found pattern at index i - j
            r.push_back(i - j);
            if (onlyFirst) {
                return r;
            }
            j = lps[j - 1];
        }

        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return r;
}

int strStr(const string A, const string B) {
    if (A.empty() || B.empty()) {
        return -1;
    }
    for (int i = 0; i < A.size(); i++) {
        bool equal = true;
        for (int j = 0; j < B.size(); j++) {
            if (i + j >= A.size() || B[j] != A[i + j]) {
                equal = false;
                break;
            }
        }

        if (equal) {
            return i;
        }
    }
    return -1;
}

string longestPalindrome(string A) {
    // The result (length of LPS) 
    int maxLength = 1;

    int start = 0;
    int len = A.size();

    // One by one consider every 
    // character as center point of 
    // even and length palindromes 
    int low, high;
    for (int i = 1; i < len; ++i) {
        // Find the longest even length palindrome 
        // with center points as i-1 and i. 
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && A[low] == A[high]) {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        // Find the longest odd length 
        // palindrome with center point as i 
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && A[low] == A[high]) {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    return A.substr(start, maxLength);
}

string reverse(string A) {
    vector<string> v;
    stringstream ss(A);

    string tmp;
    while (getline(ss, tmp, ' ')) {
        if (!tmp.empty()) {
            v.push_back(tmp);
        }
    }

    string r;
    for (int i = v.size() - 1; i >= 0; i--) {
        r += v[i];
        if (i != 0) {
            r += ' ';
        }
    }
    return r;
}

int atoi(const string A) {    
    long long r = 0;       
    int s = 1;
    for (int i = 0; i < A.size(); i++) {
        if (i == 0) {
            while (A[i] == ' ') {
                i++;
            }

            if (A[i] == '+') {
                continue;
            }

            if (A[i] == '-') {
                s = -1;
                continue;
            }
        }

        if (isdigit(A[i])) {
            r = r * 10  + (A[i] - '0');
            if (r >= INT_MAX) {
                return s > 0 ? INT_MAX : INT_MIN;
            }
        }
        else {
            break;
        }
    }
    return (int)(r * s);
}

int isNumber(const string A) {
    int lw = 0, hi = A.size() - 1;

    while (A[lw] == ' ') lw++;
    while (A[hi] == ' ') hi--;

    if (lw > hi || A[hi] < '0' || A[hi]>'9') return 0;
    
    bool next_neg = true, next_e = false, next_dot = true, e = false;    
    for (int i = lw; i <= hi; i++) {
        if (A[i] == '-' && next_neg) {
            next_e = false;
            next_neg = false;
        }
        else if (A[i] == '.' && next_dot) {
            next_dot = false;
            next_e = false;
            next_neg = false;
        }
        else if (A[i] == 'e' && next_e) {
            e = true;
            next_e = false;
            next_neg = true;
            next_dot = false;
        }
        else if (A[i] >= '0' && A[i] <= '9') {
            if (!e) next_e = true;
            next_neg = false;
        }
        else {
            return 0;
        }
    }
    return 1;
}

unsigned long long parse(const string& s, int& i) {
    unsigned long long r = 0;
    while (i < s.size() && s[i] != '.') {
        r = r * 10 + s[i++] - '0';
    }
    return r;
}

int compareVersion2(string A, string B) {
    int i1 = 0;
    int i2 = 0;
    while (i1 < A.size() || i2 < B.size()) {
        unsigned long long v1 = parse(A, i1);
        unsigned long long v2 = parse(B, i2);
        if (v1 < v2)
            return -1;
        else if (v1 > v2) {
            return 1;
        }
        i1++;
        i2++;
    };
    return 0;
}

int compareVersion(string A, string B) {
    int i = 0, j = 0, len1 = A.size(), len2 = B.size();
    while (i < len1 || j < len2) {
        unsigned long long num1 = 0, num2 = 0;
        while (i < len1 && A[i] != '.')
            num1 = num1 * 10 + (A[i++] - '0');

        while (j < len2 && B[j] != '.')
            num2 = num2 * 10 + (B[j++] - '0');

        if (num1 != num2) return num1 < num2 ? -1 : 1;
        i++, j++;
    }
    return 0;
}

int romanToInt(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}

int romanToInt(string A) {
    int r = 0;
    for (int i = 0; i < A.size(); i++) {
        int r1 = romanToInt(A[i]);
        if (i + 1 < A.size()) {
            int r2 = romanToInt(A[i + 1]);
            if (r2 > r1) {
                r += r2 - r1;
                i++;
            }
            else {
                r += r1;
            }
        }
        else {
            r += r1;
        }
    }
    return r;
}

string addBinary(string A, string B) {

    int na = A.size();
    int nb = B.size();

    if (na < nb) {
        A.insert(0, nb - na, '0');
    }
    else if (nb < na) {
        B.insert(0, na - nb, '0');
    }

    string r;
    char rem = '0';
    for (int i = A.size() - 1; i >= 0; i--) {
        if ((A[i] == '1' && B[i] == '0') || (A[i] == '0' && B[i] == '1')) {
            if (rem == '0') {
                r += '1';
            }
            else {
                r += '0';
                rem = '1';
            }
        }
        else if (A[i] == '1' && B[i] == '1') {
            if (rem == '1') {
                r += '1';                
            }
            else {
                r += '0';
                rem = '1';
            }
        }
        else {
            if (rem == '1') {
                r += '1';
                rem = '0';
            }
            else {
                r += '0';
            }
        }
    }

    if (rem == '1') {
        r += '1';
    }

    reverse(r.begin(), r.end());
    return r;
}

vector<string> fullJustify(vector<string>& A, int B) {
    vector <string> ans;
    for (int i = 0; i < A.size();) {
        int s = 0, n = 1, old_i = i, j;
        string line;
        s = A[i].size();
        i++;
        /*  n = no of words in a line
            n-1  = no of gaps
            s = max possible lenght with 1 spacing in a line
        */
        while (((s + A[i].size() + n) <= B) && i < A.size()) {
            s = s + A[i].size();
            i++;
            n++;
        }
        //single element in a line 
        if (n == 1) {
            line = A[i - 1];
            line = line + string(B - line.size(), ' ');
            ans.push_back(line);
            continue;
        }
        //last line 
        if (i == A.size()) {
            for (j = old_i; j < i - 1; j++)
                line = line + A[j] + ' ';
            line = line + A[j];
            line = line + string(B - line.size(), ' ');
            ans.push_back(line);
            break;
        }
        //ususal case
        int q = (B - s) / (n - 1);
        int r = (B - s) % (n - 1);
        for (j = old_i; j < i - 1; j++) {
            line = line + A[j];
            if (r) {
                line = line + string(q + 1, ' ');
                r--;
            }
            else
                line = line + string(q, ' ');
        }
        line = line + A[j];
        ans.push_back(line);
    }
    return ans;
}

string zigZagConcat(string A, int B)
{
    // Corner Case (Only one row) 
    if (B == 1) {
        return A;
    }

    // Create an array of strings for all n rows 
    vector<string> arr(B, "");

    // Initialize index for array of strings arr[] 
    int row = 0;
    bool down; // True if we are moving down in rows, else false 

    // Travers through given string 
    for (int i = 0; i < A.length(); ++i)
    {
        // append current character to current row 
        arr[row].push_back(A[i]);
                 
        if (row == B - 1)
            // If last row is reached, change direction to 'up'
            down = false;
        else if (row == 0)
            // If 1st row is reached, change direction to 'down' 
            down = true;

        // If direction is down, increment, else decrement 
        (down) ? (row++) : (row--);
    }

    string r;
    for (int i = 0; i < B; ++i)
        r += arr[i];
    return r;
}