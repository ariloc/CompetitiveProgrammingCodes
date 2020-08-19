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

const int MAXN = 1005;

int stage[MAXN][MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) forn(j,m) cin >> stage[i][j];

    ll rta = 0; bool valid;
    forn(i,n) {valid = false; forn(j,m) {if (stage[i][j]) valid = true; else if (valid) rta++;}}
    forn(i,n) {valid = false; dforn(j,m) {if (stage[i][j]) valid = true; else if (valid) rta++;}}
    forn(j,m) {valid = false; forn(i,n) {if (stage[i][j]) valid = true; else if (valid) rta++;}}
    forn(j,m) {valid = false; dforn(i,n) {if (stage[i][j]) valid = true; else if (valid) rta++;}}

    cout << rta;

    return 0;
}

/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!