#pragma once

int gcd(int A, int B) {
    if (B == 0) {
        return A;
    }
    return gcd(B, A % B);
}

int cpFact(int A, int B) {
    while (gcd(A, B) != 1) {
        A = A / gcd(A, B);
    }
    return A;
}