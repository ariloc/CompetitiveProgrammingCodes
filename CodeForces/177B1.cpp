#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i<int(n); i++)

using namespace std;
typedef vector<int> vi;
typedef long long ll;

ll factS(ll n) {
    ll r = n;
    for (int p = 2; p*p<=n; p++) {
        while(n%p == 0) {
            n/=p;
            r+=n;
        }
    }
    if (n != 1) r++;
    return r;
}

int main() {
    int N, r;
    cin >> N;
    cout << factS(N);
    return 0;
}