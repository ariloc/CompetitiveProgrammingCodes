#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    ll n,k,s; cin >> n >> k >> s;

    if (k > s) {cout << "NO"; return 0;}

    vi moves;
    ll spend = s/(n-1);
    //if ((spend * (n-1)) == s and spend != k) spend--;
    while (s-(spend * (n-1)) < k-spend) spend--;
    k -= spend; s -= (spend * (n-1));
    if (k < 0 or (!k and s)) {cout << "NO"; return 0;}
    forn (i,spend) {
        if (i & 1) moves.pb(1);
        else moves.pb(n);
    }

    if ((moves.empty() or moves.back() == 1))
        forn (i,k-1) {if (i & 1) moves.pb(1); else moves.pb(2); s--;}
    else forn (i,k-1) {if (i & 1) moves.pb(n); else moves.pb(n-1); s--;}

    int lastV = (moves.empty() ? 1 : moves.back());
    if (k) moves.pb((lastV+s > n ? lastV-s : lastV+s));

    cout << "YES\n";
    for (auto &i : moves) cout << i << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!