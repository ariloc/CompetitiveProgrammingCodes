#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
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
typedef long double ld;

const int MAXN = 2e5+5;
const int MOD = 1e9+7;

int dp[MAXN][2];
vi G[MAXN];
int inDeg[MAXN];
int n;

int rta = 0;
int solve (int st, int odd) {
    if (dp[st][odd] != -1) return dp[st][odd];
    int m = G[st].size();
    int ret = odd;
    int acc[2] = {0,0};

    if (!G[st].empty()) {
        for (auto &i : G[st]) {
            int s_odd = solve(i,1), s_even = solve(i,0);
            int tmp_even = ((acc[0] + (acc[0] * (ll)s_even)%MOD)%MOD + ((acc[1] * (ll)s_odd)%MOD + s_even)%MOD)%MOD;
            int tmp_odd = ((acc[1] + (acc[1] * (ll)s_even)%MOD)%MOD + ((acc[0] * (ll)s_odd)%MOD + s_odd)%MOD)%MOD;
            acc[0] = tmp_even, acc[1] = tmp_odd;
        }

        ret = (ret + acc[1^odd])%MOD;
    }

    if (odd) rta = (rta + ret)%MOD;
    return dp[st][odd] = ret;
}

int impares(vector<vector<int>> &subordinados) {
    forn(i,MAXN) dp[i][0] = dp[i][1] = -1;
    n = (int)subordinados.size();
    forn(i,n)
        for (auto &j : subordinados[i]) {
            G[i].pb(j);
            inDeg[j]++;
        }

    int gerente = -1;
    forn(i,n) if (!inDeg[i]) {
        gerente = i; break;
    }

    solve(gerente, 1);
    return rta;
}
