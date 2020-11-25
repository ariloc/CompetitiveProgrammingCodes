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

const int MAXN = 2e5+2;
const int INF = 2e9+5;

struct voucher {
    int l,r,c;

    bool operator< (const voucher &o) const {
        return l < o.l;
    }
};

voucher avail[MAXN];
vector<ii> ranges[MAXN];

int main() {
    FAST_IO;

    int n,x; cin >> n >> x;
    forn(i,n) {
        int l,r,c; cin >> l >> r >> c;
        avail[i] = {l,r,c};
    }

    sort(avail,avail+n);

    map<int,int> past;
    int mini = INF, j = 0;
    forn(i,MAXN) { // para cada coord en x
        while (j <= n && avail[j].l == i) {
            int d = avail[j].r-avail[j].l+1;
            ranges[avail[j].r].pb({d,avail[j].c});
            auto it = past.find(x-d);
            if (it != past.end()) mini = min(mini,avail[j].c+(*it).snd);
            j++;
        }

        for (auto &k : ranges[i]) {
            if (!past.count(k.fst)) past[k.fst] = k.snd;
            else past[k.fst] = min(past[k.fst],k.snd);
        }
    }

    cout << (mini == INF ? -1 : mini);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
