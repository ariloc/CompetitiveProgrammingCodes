#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;
typedef vector<int> vi;

int const MAXN = 105;

vi primes,ot;

int main() {
    FAST_IO;

    forsn(i,2,51) {
        bool prime = true;
        forsn(j,2,i) if (!(i%j)) prime = false;
        if (prime) primes.pb(i);
    }
    for (auto &j : primes) {
        if (j*j > 100) break;
        ot.pb(j*j);
    }

    int cnt = 0;
    for (auto &j : primes) {
        cout << j << endl;
        string s; cin >> s;
        if (s == "yes") ++cnt;
    }

    if (cnt >= 2) {
        cout << "composite" << endl;
        return 0 ;
    }

    bool ok2 = true;
    for (auto &j : ot) {
        cout << j << endl;
        string s; cin >> s;
        if (s == "yes") ok2=false;
    }

    cout << (ok2 ? "prime" : "composite") << endl;

    return 0;
}
