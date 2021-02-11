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

const int MAXN = 1e6+5; // margen
const ll INF = 9e18;

int coords[MAXN];
pair<ll,ii> dpR[MAXN], dpL[MAXN]; // suma, contador de esta tanda, contador de tandas de m

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d",&coords[i+1]);

    dpR[n] = {0,{0,1}};
    dforsn(i,1,n) {
        dpR[i].snd.fst = dpR[i+1].snd.fst+1;
        dpR[i].snd.snd = dpR[i+1].snd.snd;
        if (dpR[i].snd.fst > m) dpR[i].snd.fst = 1, dpR[i].snd.snd++;
        dpR[i].fst = dpR[i+1].fst + (coords[i+1]-coords[i])*2LL*dpR[i].snd.snd;
    }

    dpL[1] = {0,{0,1}};
    forsn(i,2,n+1) {
        dpL[i].snd.fst = dpL[i-1].snd.fst+1;
        dpL[i].snd.snd = dpL[i-1].snd.snd;
        if (dpL[i].snd.fst > m) dpL[i].snd.fst = 1, dpL[i].snd.snd++;
        dpL[i].fst = dpL[i-1].fst + (coords[i]-coords[i-1])*2LL*dpL[i].snd.snd;
    }

    ll mini = INF;
    forsn(i,1,n+1) {
        int tR = upper_bound(coords+1,coords+n+1,coords[i])-coords-1; // agarro el último en mi posic
        int tL = lower_bound(coords+1,coords+n+1,coords[i])-coords; // agarro el primero en mi posic
        mini = min(mini,dpL[tL].fst+dpR[tR].fst);
    }

    printf("%lld",mini);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
