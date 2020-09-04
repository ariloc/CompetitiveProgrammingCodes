#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 3e5+5;

set<int> living;
int rta[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) living.insert(i+1);

    forn(i,m) {
        vi won;
        int l,r,w; cin >> l >> r >> w;
        auto it = living.lower_bound(l);
        while(it != living.end() and *(it) <= r) {won.pb(*it); it++;}
        for (auto &j : won)
            if (j != w) {
                rta[j] = w;
                living.erase(j);
            }
    }

    forsn(i,1,n+1) cout << rta[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
