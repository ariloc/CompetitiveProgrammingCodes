#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 1e5+5;
const int MOD = 112345687;

int binMod (int a, ll k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

struct edges {
    int v;
    ll w[2];
};

vector<edges> G[MAXN];
int inDeg[MAXN], outDeg[MAXN];
ll dp[MAXN][2];

int toriis(int N, vector<int> &inicio, vector<int> &fin, vector<long long> &cantidad) {
    int M = (int)fin.size();
    forn(i,M) {
        int u = inicio[i]-1, v = fin[i]-1;
        ll w = cantidad[i];

        ll cant = w >= 1 ? binMod(2,w-1) : 1;

        G[u].pb({v, {cant,cant - (w==0)}});
        inDeg[v]++, outDeg[u]++;
    }

    forn(i,N) if (!inDeg[i]) dp[i][0] = 1;

    queue<int> Q;
    forn(i,N) if (!inDeg[i]) Q.push(i);

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        for (auto &i : G[e]) {
            dp[i.v][0] = (dp[i.v][0] + (((ll)dp[e][0] * (ll)i.w[0])%MOD))%MOD;
            dp[i.v][0] = (dp[i.v][0] + (((ll)dp[e][1] * (ll)i.w[1])%MOD))%MOD;

            dp[i.v][1] = (dp[i.v][1] + (((ll)dp[e][0] * (ll)i.w[1])%MOD))%MOD;
            dp[i.v][1] = (dp[i.v][1] + (((ll)dp[e][1] * (ll)i.w[0])%MOD))%MOD;
            if (!(--inDeg[i.v])) Q.push(i.v);
        }
    }

    int rta = 0;
    forn(i,N) if (!outDeg[i]) rta = (rta + (ll)dp[i][0])%MOD;

    return rta;
}
