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

const int MAXN = 1005;
const int INF = 1e9+5;

ii targets[MAXN];
int penTAd[MAXN];
ld dp[MAXN];

int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        if (!n) break;

        targets[0] = {0,0}; // reset
        targets[n+1] = {100,100};
        penTAd[0] = penTAd[n+1] = 0;
        forsn(i,1,n+2) dp[i] = INF;

        forn(i,n) scanf("%d %d %d",&targets[i+1].fst,&targets[i+1].snd,&penTAd[i+1]);
        forsn(i,1,n+2) penTAd[i] += penTAd[i-1];

        forsn(i,1,n+2) forn(j,i)
            dp[i] = min(dp[i],dp[j]+hypot(abs(targets[j].fst-targets[i].fst),abs(targets[j].snd-targets[i].snd))+penTAd[i-1]-penTAd[j]+1);

        printf("%.3Lf\n",dp[n+1]);
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
