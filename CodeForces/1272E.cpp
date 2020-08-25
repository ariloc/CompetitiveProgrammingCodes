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

const int MAXN = 2e5+5;
const int INF = 1e9+5;

int arr[MAXN],rta[MAXN];
bitset<MAXN> done;
int n;

vi G[MAXN]; // get to me

int main() {
    FAST_IO;

    forn(i,MAXN) rta[i] = INF;
    cin >> n;
    forn (i,n) cin >> arr[i];
    forn(i,n) { // generar grafo a los que llega c/u
        int der = i+arr[i], izq = i-arr[i];
        if (der < n and (arr[der]&1)==(arr[i]&1)) G[der].pb(i);
        if (izq >= 0 and (arr[izq]&1)==(arr[i]&1)) G[izq].pb(i);
    }

    vi Q[2];
    forn (i,n) {
        if (i+arr[i] < n and (arr[i+arr[i]]&1)!=(arr[i]&1)) {Q[0].pb(i); done[i] = true;}
        else if (i-arr[i] >= 0 and (arr[i-arr[i]]&1)!=(arr[i]&1)) {Q[0].pb(i); done[i] = true;}
    }

    int look = 0, cnt = 1;
    while (not Q[0].empty() or not Q[1].empty()) {
        while (not Q[look].empty()) {
            auto e = Q[look].back(); Q[look].pop_back();

            //cerr << e << ' ' << cnt << endl;
            rta[e] = cnt;

            for (auto &i : G[e])
                if (!done[i]) {Q[(look+1)%2].pb(i); done[i] = true;}

        }
        cnt++;
        look = (look+1)%2;
    }

    forn(i,n) cout << (rta[i] < INF ? rta[i] : -1) << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
