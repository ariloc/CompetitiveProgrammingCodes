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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 3e5+5;

vi G[MAXN]; // v,id
int col[MAXN], conflicts[MAXN];

int main() {
    int n,m; scanf("%d %d",&n,&m);

    forn(i,m) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        G[u].pb(v), G[v].pb(u);
        conflicts[u]++, conflicts[v]++;
    }

    queue<int> Q;
    forn(i,n) Q.push(i);

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (conflicts[e] <= 1) continue;

        for (auto &i : G[e])
            if (col[i] == col[e]) conflicts[i]--, conflicts[e]--;
            else {
                if (conflicts[i] == 1) Q.push(i);
                conflicts[i]++, conflicts[e]++;
            }

        col[e] ^= 1;
    }

    forn(i,n) printf("%d",col[i]);

    return 0;
}