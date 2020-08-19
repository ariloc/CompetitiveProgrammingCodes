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

const int INF = 1e9+2;
const int MAXN = 2e5+2;

int war[MAXN],dest[MAXN];
bitset<MAXN> done;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    ll x,k,y; cin >> x >> k >> y;

    forn (i,n) cin >> war[i]; done[n] = 1; war[n] = -1;
    int ind = 0, mark = 0;
    forn (i,m) {
        cin >> dest[i];
        while (ind < n and war[ind] != dest[i]) ind++;
        if (war[ind] == dest[i]) {done[ind] = true; mark++;}
    }

    //forn(i,n+1) cout << done[i];

    if (mark < m) {cout << -1; return 0;}

    bool posib = true;
    int maxi = -1, l = -1, cnt = 0;
    ll rta = 0;
    forn (i,n+1) {
        if (done[i]) {
            if (cnt) {
                if (maxi > l and maxi > war[i] and (war[i] != l)) {
                    if (k > cnt) {posib = false; break;}
                    if ((x/k) >= y) rta += (y*(cnt-k))+x;
                    else rta += ((y*(cnt%k)) + (x*(cnt/k)));
                } else rta += min((y*cnt),((y*(cnt%k)) + (x*(cnt/k))));
            }

            maxi = -1; l = war[i]; cnt = 0;
        } else {maxi = max(maxi,war[i]); cnt++;}
    }

    if (posib) cout << rta; else cout << -1;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!