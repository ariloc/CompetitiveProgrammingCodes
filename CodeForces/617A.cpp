#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0 ; i < int(n); i++)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,r =0;
    cin >> N;

    r+=N/5;
    N=N%5;
    r+=N/4;
    N=N%4;
    r+=N/3;
    N=N%3;
    r+=N/2;
    N=N%2;
    r+=N/1;

    cout << r;
}