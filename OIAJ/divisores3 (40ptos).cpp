#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 1e6+5;
const int MAXK = 51;
const ll INF = 9e18;

void fact(ll x, map<ll,int> &F) {
    for (ll i = 2; i*i <= x; i++)
        while (!(x%i)) x /= i, F[i]++;
    if (x > 1) F[x]++;
}

//bitset<MAXN> done;
//ll D[MAXN][MAXK];
ll dp[MAXN],MOD;
int spf[MAXN];

void criba () {
    forn(i,MAXN) spf[i] = i;
    for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
    for (int i = 3; i*i <= MAXN; i += 2)
        if (spf[i] == i)
            for (int j = i+i; i < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
}

struct op {
    ll x,acc;
};

ll calc (ll N, ll M) {
    ll aux = (((N%M)*(N%M))%M);
    return aux * aux;
}

ll solve (ll N, bool turn) { // 1 es Gastón, 0 es Agustín
    if (N == 1) return calc(1,MOD);
    if (dp[N] != -1) return dp[N];

    map<ll,int> F;
    ll aux = N;
    for (int i = 2; i*i <= aux; i++)
        while (!(aux%i)) F[i]++, aux /= i;
    if (aux > 1) F[aux]++;

    ll val = (turn ? -INF : INF);
    for (auto &i : F) {
            //cerr << N << ' ' << i.fst <<  "!!!" << endl;
        if (!turn) val = min(val,solve(N/i.fst,1-turn));
        else val = max(val,solve(N/i.fst,1-turn));
    }

    return dp[N] = val + calc(N,MOD);
}

vector<long long> divisores(long long N, long long M) {
    //criba();
    MOD = M;

    vector<ll> rtas;
    forn(i,MAXN) dp[i] = -1; dp[1] = 0;
    rtas.pb(solve(N,0));
    forn(i,MAXN) dp[i] = -1; dp[1] = 0;
    rtas.pb(solve(N,1));

    return rtas;

    /*
    mini[N] = maxi[N] = calc(N);
    dforsn(i,2,N+1) {
        ll aux = i;

        set<ll> divs;
        while (spf[aux] != aux) {
            aux /= spf[aux];
            divs.insert(spf[aux]);
        }
        if (aux > 1) divs.insert(aux);

        for (auto &j : divs) {
            int tg = i/j;
            mini[tg] = min(mini[tg],mini[i] + calc(tg));
            mini[tg] = min(mini[tg],mini[i] + calc(tg));
        }
    }*/


}
