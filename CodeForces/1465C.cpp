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

const int MAXN = 1e5+20;

bitset<MAXN> done,passed;
int nxt[MAXN],inDegree[MAXN];
ii rooks[MAXN];

bool dfs (int st) {
    if (done[st]) return true;
    done[st] = true;
    if (nxt[st] && !passed[st] && nxt[st]-1 != st) {passed[st] = true; return dfs(nxt[st]-1);}
    passed[st] = true;
    return false;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;
        int rta = 0, cnt = 0;
        forn(j,m) {
            int x,y; cin >> x >> y; x--; y--;
            rooks[j] = {y,x};
            nxt[x] = y+1; inDegree[y]++;
            if (x == y) cnt++;
        }
        forn(j,n) if (!inDegree[j] && !passed[j]) rta += dfs(j);
        forn(j,n) if (!passed[j]) rta += dfs(j);
        forn(j,n) done[j] = (passed[j] = (inDegree[j] = (nxt[j] = 0)));

        cout << m-cnt+rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
