#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 2e5+5;
const int INF = 2e9;

int arr[MAXN], tg[MAXN];
int ady[4][4];
vi G[MAXN];

int rta = 0;

int dfs(int st, int ini, int mk, int avail) {
    if (!avail) return 0;
    if (ady[st][ini]) {
        int aux = min(avail, ady[st][ini]);
        ady[st][ini] -= aux;
        return aux;
    }

    int spent = 0;
    forn(i,4) {
        if (spent >= avail) break;
        if (mk&(1<<i)) continue;
        if (!ady[st][i]) continue;
        int aux = dfs(i, ini, mk|(1<<i), min(ady[st][i],avail-spent));
        spent += aux;
        ady[st][i] -= aux;
        rta += aux;
    }

    return spent;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i], --arr[i];

    int cnt[] = {0,0,0,0};
    forn(i,n) cnt[arr[i]]++;

    int ind = 0;
    forn(i,n) {
        while (!cnt[ind]) ++ind;
        tg[i] = ind;
        cnt[ind]--;
    }

    forn(i,n) {
        if (arr[i] != tg[i]) ady[tg[i]][arr[i]]++;
    }

    forn(i,4) {
        dfs(i,i,(1<<i),INF);
    }

    cout << rta;
      
    return 0;
}
