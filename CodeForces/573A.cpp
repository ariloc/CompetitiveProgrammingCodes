#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);


using namespace std;

int main() {
    FAST_IO;

    int n; cin >> n;
    vector<int> arr;
    forn(i,n) {
        int x; cin >> x;
        arr.pb(x);
    }

    int x = arr[0];
    forsn(i,1,n) {
        x = __gcd(x,arr[i]);
    }

    bool ok = true;
    forn(i,n) {
        int d = arr[i]/x;
        while (d > 1 && !(d%2)) d /= 2;
        while (d > 1 && !(d%3)) d /= 3;
        if (d>1) ok = false;
    }

    cout << (ok ? "Yes" : "No") << '\n';

    return 0;
}
