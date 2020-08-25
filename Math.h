#pragma once

#include <vector>
#include <string>

using namespace std;

int isPrime(int A) {
    if (A < 2)
        return 0;

    for (int i = 2; i * i <= A; i++) {
        if (A % i == 0)
            return 0;
    }
    return 1;
}

vector<int> sieve(int A) {
    vector<bool> isprime(A + 1, true);
    for (int i = 2; i * i <= A; i++) {
        // If prime[p] is not changed, then it is a prime 
        if (isprime[i]) {
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int j = i * i; j <= A; j += i) {
                isprime[j] = false;
            }
        }
    }

    vector<int> result;
    for (int i = 2; i < isprime.size(); i++) {
        if (isprime[i]) {
            result.push_back(i);
        }
    }
    return result;
}

string findDigitsInBinary(int A) {

    if (A == 0) {
        return "0";
    }

    string result;
    while (A > 0) {
        int rem = A % 2;
        result += to_string(rem);
        A = A / 2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

string findDigitsInBinary2(int A) {
    string r;
    if (A / 2 == 0) {
        r = "";
    }
    else {
        r = findDigitsInBinary(A / 2);
    }
    return r + to_string(A % 2);
}

vector<int> allFactors(int A) {
    vector<int> r;
    for (int i = 1; i * i < A; i++) {
        if (A % i == 0) {
            r.push_back(i);
        }
    }
    for (int i = sqrt(A); i >= 1; i--) {
        if (A % i == 0) {
            r.push_back(A / i);
        }
    }
    return r;
}

vector<int> primesum(int A) {
    vector<bool> primes(A + 1, true);
    for (int i = 2; i * i <= A; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= A; j += i) {
                primes[j] = false;
            }
        }
    }

    for (int i = 2; i < primes.size(); i++) {
        if (primes[i] && primes[A - i] && i + A - i == A) {
            return { i, A - i };
        }
    }
    return { 0, 0 };
}

int isPower(int A) {
    if (A == 1)
        return true;

    for (int i = 2; i * i <= A; i++) {
        if (A % i == 0) {
            if ((A / i) == i)
                return true;
            else if (isPower(A / i) && (A / i) % i == 0)
                return true;
        }
    }
    return false;
}

int isPower2(int A)
{
    if (A == 1)
        return 1;

    for (int i = 2; i * i <= A; i++) {
        long long int num = 1;
        while (true) {
            num = num * i;
            if (num == A)
                return 1;
            else if (num > A)
                break;
        }
    }
    return 0;
}

int isPower3(int A)
{
    if (A == 1)
        return 1;
        
    for (int i = 2; i * i <= A; i++) {
        int x = log(A) / log(i);
        if (pow(i, x) == A)
            return 1;
    }
    return 0;
}

vector<string> fizzBuzz(int A) {
    vector<string> r;
    for (int i = 1; i <= A; i++) {
        string s;
        if (i % 3 == 0) {
            s += "Fizz";
        }
        if (i % 5 == 0) {
            s += "Buzz";
        }
        if (s.empty()) {
            s = to_string(i);
        }
        r.push_back(s);
    }
    return r;
}

int titleToNumber(string A) {
    int sum = 0;
    for (auto i : A)
        sum = 26 * sum + (i - 'A' + 1);
    return sum;
}

string convertToTitle(int A) {
    string r;
    while (A != 0) {
        // subsctract 1 from A to avoid A % 26 == 0 
        A--;
        r = char('A' + A % 26) + r;
        A /= 26;
    }
    return r;
}

