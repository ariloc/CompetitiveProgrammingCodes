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

const int MAXN = 1e5+2;
const int INF = 1e9+5;
const int MAXR = 1005; // 2*r, max dist, el resto los alcanzo siempre

pair<int,ii> cel[MAXN];
int dp[MAXN]; // llegando a cel

int main() {
    forsn(i,1,MAXN) dp[i] = -INF; // reset
    int r,n; scanf("%d %d",&r,&n);
    cel[0] = {0,{1,1}}; // yo
    forn(i,n) scanf("%d %d %d",&cel[i+1].fst,&cel[i+1].snd.fst,&cel[i+1].snd.snd);

    forsn(i,1,n+1) forsn(j,1,(4*r)+2)
        if (i-j >= 0 && (cel[i-j].fst+abs(cel[i-j].snd.fst-cel[i].snd.fst)+abs(cel[i-j].snd.snd-cel[i].snd.snd)) <= cel[i].fst) // si es vaĺido y llego
            dp[i] = max(dp[i],dp[i-j]+1);

    int maxi = 0;
    forn(i,MAXN) maxi = max(maxi,dp[i]);

    printf("%d",maxi);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
