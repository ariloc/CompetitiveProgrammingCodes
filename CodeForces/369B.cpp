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

int main() {
    FAST_IO;

    int n,k,l,r,sall,sk; cin >> n >> k >> l >> r >> sall >> sk;
    int rest = sall-sk;
    vi restA;
    forn(i,n-k) restA.pb(l);
    rest -= l*(n-k);
    int ind = 0;
    while (rest > 0) {
        restA[ind]++; rest--;
        ind = (ind+1)%(n-k);
    }
    sort (all(restA));
    for (auto &i : restA) cout << i << ' ';
    vi top;
    forn(i,k) top.pb(l);
    ind = 0; sk -= l*k;
    while (sk > 0) {
        top[ind]++; sk--;
        ind = (ind+1)%k;
    }
    sort(all(top));
    for (auto &i : top) cout << i << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
