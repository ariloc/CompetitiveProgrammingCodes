#include <algorithm>
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

const int MAXN = 505;

vi G[MAXN];
bitset<MAXN> done, done2;
int match[MAXN];

bool try_kuhn (int st) {
    if (done[st]) return false;
    done[st] = true;

    for (auto &i : G[st])
        if (match[i] == -1 || try_kuhn(match[i])) {
            match[i] = st;
            return true;
        }

    return false;
}

int main() {
    int n,m,k; scanf("%d %d %d",&n,&m,&k);

    bool swapped = false;
    if (m < n) swapped = true, swap(n,m);

    forn(i,m) match[i] = -1;

    forn(i,k) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        if (swapped) swap(u,v);
        G[u].pb(v);
    }

    forn(i,n)
        for (auto &j : G[i])
            if (match[j] == -1) {
                match[j] = i;
                done2[i] = true;
                break;
            }

    forn(i,n) {
        if (done2[i]) continue;
        forn(j,n) done[j] = false;
        try_kuhn(i);
    }

    vector<ii> rta;
    forn(i,m)
        if (match[i] != -1) {
            if (swapped) rta.pb({i,match[i]});
            else rta.pb({match[i],i});
        }

    printf("%d\n", (int)rta.size());
    for (auto &i : rta) printf("%d %d\n", i.fst+1, i.snd+1);
 
    return 0;
}
