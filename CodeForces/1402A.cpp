
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

const int MAXN = 1e5+5;
const int INF = 1e9+5;
const int MOD = 1e9+7;

ll W[MAXN],H[MAXN];
int minR[MAXN],minL[MAXN];

ll gaussMOD (ll x) {
    return (((x*(x+1))%MOD)*(MOD+1)/2)%MOD;
}

int main() {
    FAST_IO;

    //freopen("input1.txt","r",stdin);

    int n; cin >> n;
    forn(i,n) cin >> H[i+1];
    forn(i,n) cin >> W[i+1];

    forsn(i,1,n+1) W[i] = (W[i]+W[i-1])%MOD;

    int j; H[0] = -INF; H[n+1] = -INF;
    dforsn(i,1,n+1) {for (j = i+1; H[j] >= H[i]; j = minR[j]); minR[i] = j;}
    forsn(i,1,n+1) {for (j = i-1; H[j] >= H[i]; j = minL[j]); minL[i] = j;}

    ll rta = 0;
    set<tuple<int,int,int>> passed;
    forsn(i,1,n+1) {
        if (passed.count({minL[i],minR[i],H[i]})) continue;
        passed.insert({minL[i],minR[i],H[i]});

        ll width = W[minR[i]-1]-W[minL[i]];
        int maxH = max(H[minR[i]],H[minL[i]]);
        rta = (rta + ((gaussMOD(H[i])*gaussMOD(width))%MOD) - (maxH != -INF ? ((gaussMOD(maxH)*gaussMOD(width))%MOD) : 0) + MOD)%MOD;
        //cerr << rta << ' ' << i << ' ' << H[i] << ' ' << ((gaussMOD(H[i])*gaussMOD(width))%MOD) << ' ' << width << ' ' << maxH << ' ' << minR[i] << ' ' << minL[i] << ' ' << H[minR[i]] << ' ' << H[minL[i]] << endl;
    }

    cout << (rta+MOD)%MOD;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
