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

const int INF = 1e9+5;
const int MAXN = 1e5+5;

int strings[6],done[MAXN];
ii pts[MAXN*6];

int main() {
    FAST_IO;

    forn(i,6) cin >> strings[i];
    int n; cin >> n;
    forn(i,n) {
        int x; cin >> x;
        forn(j,6) pts[i*6+j] = (strings[j] >= x ? (ii){INF,i} : (ii){x-strings[j],i});
    }
    sort(pts,pts+(n*6));
    int top = n*6;
    dforn(i,n*6) if (pts[i].fst == INF) top--; else break; // establezco límite para two pointers

    int r = 0, cnt = 0, rta = INF;
    forn(i,top) {
        while (r < top && cnt < n) {
            if (!done[pts[r].snd]) cnt++;
            done[pts[r].snd]++; r++;
        }
        if (cnt == n) rta = min(rta,pts[r-1].fst-pts[i].fst);
        done[pts[i].snd]--; if (!done[pts[i].snd]) cnt--;
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
