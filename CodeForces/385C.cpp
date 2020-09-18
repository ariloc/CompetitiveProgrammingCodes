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

const int MAXD = 1e7+5;

int mark[MAXD]; ll myMult[MAXD];
bitset<MAXD> done;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x; cin >> x;
        mark[x]++;
    }

    for (int i = 2; i < MAXD; i+=2) {done[i] = true; myMult[2] += mark[i];}
    for(int i = 3; i*i < MAXD; i+=2)
        if (!done[i])
            for (int j = i+i; j < MAXD; j+=i)
                done[j] = true;

    for (int i = 3; i < MAXD; i+=2) if (!done[i])
        for (int j = i; j < MAXD; j+=i) myMult[i] += mark[j];

    forsn(i,1,MAXD) myMult[i] += myMult[i-1];

    int m; cin >> m;
    forn(i,m) {
        int l,r; cin >> l >> r;
        r = min(r,MAXD-1); if (l >= MAXD) {cout << "0\n"; continue;}
        cout << myMult[r]-myMult[l-1] << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!

