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

const int MAXN = 55;
const int INF = 1e9+5;

ii arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        ii mini = {INF,INF};
        forn(j,n) {
            cin >> arr[j].fst;
            mini.fst = min(arr[j].fst,mini.fst);
        }
        forn(j,n) {
            cin >> arr[j].snd;
            mini.snd = min(arr[j].snd,mini.snd);
        }

        ll rta = 0;
        forn(j,n) {
            int dif = min(arr[j].snd-mini.snd,arr[j].fst-mini.fst);
            rta += dif; arr[j].fst -= dif; arr[j].snd -= dif;
            rta += arr[j].snd-mini.snd; rta += arr[j].fst-mini.fst;
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
