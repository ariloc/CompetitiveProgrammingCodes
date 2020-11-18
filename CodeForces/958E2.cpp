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

const int MAXN = 5e5+5;
const int MAXK = 5005;
const int MAXD = 2*MAXK+5;
const int INF = 1e9+5;

int dp[MAXK][2][2]; // dado el k, la dimensión (voy alternando y ahorro memoria), y si agarro o no este
ii gaps[MAXN];

int main() {
    int n,k; scanf("%d %d",&k,&n);
    forn(i,n) scanf("%d",&gaps[i].fst);
    sort(gaps,gaps+n);
    forsn(i,1,n) gaps[i-1] = {gaps[i].fst-gaps[i-1].fst,i-1};
    sort(gaps,gaps+(n-1)); // hay un elemento menos
    int bstTop = 2*k+5;
    sort(gaps,gaps+(min(n-1,bstTop)),[](const ii &a, const ii &b){return a.snd < b.snd;}); // los ordeno a los bstTop más chicos por posición

    forn(i,2) forn(j,MAXK) dp[j][i][0] = dp[j][i][1] = INF;
    dp[0][0][0] = 0; dp[1][0][1] = gaps[0].fst;
    int ind = 1, rta = INF;
    if (k == 1) rta = min(rta,gaps[0].fst);

    forsn(i,1,min(bstTop,n-1)) {
        forn(j,MAXK) dp[j][ind][0] = dp[j][ind][1] = INF;
        forn(j,k+1) {
            dp[j][ind][0] = min({dp[j][ind][0],dp[j][(ind+1)&1][0],dp[j][(ind+1)&1][1]});
            if (j) dp[j][ind][1] = min(dp[j][ind][1],dp[j-1][(ind+1)&1][0]+gaps[i].fst);
            if (abs(gaps[i].snd-gaps[i-1].snd) > 1 && j) dp[j][ind][1] = min(dp[j][ind][1],dp[j-1][(ind+1)&1][1]+gaps[i].fst);
            if (j == k) rta = min({rta,dp[j][ind][0],dp[j][ind][1]});
        }
        ind = (ind+1)&1;
    }

    printf("%d",rta);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
