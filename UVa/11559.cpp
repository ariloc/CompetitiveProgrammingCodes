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

const int MAXH = 18;
const int MAXW = 13;
const ll INF = 9e18;

int avail[MAXH][MAXW];
int vals[MAXH];

int main() {
    int n,b,h,w;
    while (scanf("%d %d %d %d",&n,&b,&h,&w) != EOF) {
        forn(i,h) {
            scanf("%d",&vals[i]);
            forn(j,w) scanf("%d",&avail[i][j]);
        }
        ll mini = INF;
        forn(i,w) forn(j,h) if (avail[j][i] >= n) mini = min(mini,(ll)n*vals[j]);

        if (mini > b) puts("stay home");
        else printf("%lld\n",mini);
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
