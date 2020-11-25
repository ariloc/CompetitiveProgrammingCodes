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

const int MAXN = 3e5+20;
const int INF = 1e9;

ii arr[MAXN];
int nfo[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n+5) {arr[j] = {-1,INF}; nfo[j] = INF;}
        forn(j,n) {
            int x; cin >> x;
            if (arr[x].fst == -1) arr[x] = {j,j+1};
            else arr[x] = {j,max(arr[x].snd,j-arr[x].fst)};
        }
        forn(j,n+5) if (arr[j].fst != -1) arr[j].snd = max(arr[j].snd,n-arr[j].fst);
        forn(j,n+5) if (arr[j].fst != -1) nfo[arr[j].snd] = min(nfo[arr[j].snd],j);
        forsn(j,1,n+5) nfo[j] = min(nfo[j],nfo[j-1]);
        forn(j,n) cout << (nfo[j+1] == INF ? -1 : nfo[j+1]) << ' ';
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
