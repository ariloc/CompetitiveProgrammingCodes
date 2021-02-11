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

const int MAXN = 5e5+5;

bool stat[MAXN];
ll acc[MAXN];
int G[MAXN][2],inDegree[MAXN];

int main() {
    FAST_IO;

    ll n; int m; cin >> n >> m;
    forn(i,m) {
        char c; int l,r; cin >> c >> l >> r; l--, r--;
        if (l == -1) l = m; // cambio a que el final sea el último de todos por conveniencia
        if (r == -1) r = m;
        inDegree[l]++, inDegree[r]++;
        G[i][0] = l, G[i][1] = r;
        stat[i] = (c == 'R');
    }

    acc[0] = n;
    queue<int> Q; forn(i,m+1) if (!inDegree[i]) Q.push(i);
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();
        if (e == m) continue; // último nodo

        bool meSt = stat[e];
        ll c1 = (acc[e]+1)/2, c2 = acc[e]/2;
        acc[G[e][meSt]] += c1; // el ceil ya que la mayoría viene
        acc[G[e][!meSt]] += c2;
        acc[e] = 0;
        if (!(--inDegree[G[e][meSt]])) Q.push(G[e][meSt]);
        if (!(--inDegree[G[e][!meSt]])) Q.push(G[e][!meSt]);
        if ((c1+c2)&1) stat[e] ^= 1;
    }

    forn(i,m) cout << (stat[i] ? 'R' : 'L');

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
