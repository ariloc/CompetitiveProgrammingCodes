#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i<int(n); i++)

using namespace std;

int main() {
    long long N, partR, org, r = 0;
    cin >> N;

    partR = N/100;
    if (partR > 0) r+=partR;
    partR = N%100;

    org = partR;
    partR = partR/20;
    if (partR > 0) r+= partR;
    partR = org%20;

    org = partR;
    partR = partR/10;
    if (partR > 0) r+= partR;
    partR = org%10;

    org = partR;
    partR = partR/5;
    if (partR > 0) r+= partR;
    partR = org%5;

    partR = partR/1;
    r+= partR;

    cout << r;

    return 0;
}