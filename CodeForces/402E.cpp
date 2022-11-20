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

const int MAXN = 2005;

int mat[MAXN][MAXN];
vi G[MAXN];
int tin[MAXN], actT = 1, prox_libre = 0;
bitset<MAXN> matched;

vi pila;
int tarjan (int st) {
    tin[st] = actT++;
    pila.pb(st);

    int mini = tin[st];
    for (auto &i : G[st]) {
        if (!tin[i]) mini = min(mini, tarjan(i));
        if (!matched[i]) mini = min(mini, tin[i]);
    }

    if (mini >= tin[st])
        while (!pila.empty()) {
            auto e = pila.back(); pila.pop_back();
            matched[e] = true;
            if (e == st) {prox_libre++; break;}
        }

    return mini;
}

int main() {
    int n; scanf("%d", &n);

    forn(i,n) forn(j,n) scanf("%d", &mat[i][j]);

    forn(i,n) forn(j,n) if (mat[i][j] > 0) G[i].pb(j);

    forn(i,n) if (!tin[i]) tarjan(i);

    printf("%s", prox_libre == 1 ? "YES" : "NO");
 
    return 0;
}
