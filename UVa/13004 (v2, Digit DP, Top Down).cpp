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

int const MAXD = 19;
int const MAXE = 59049;
int const DIG = 10;
ll const INF = 5e17;

ll dp[MAXD][MAXE][2];
int pot3[DIG];
int n;
vi decomp;

ll solve (int p, int mk, int lower) {
    if (p < 0) return (lower ? -INF : 0LL);
    if (dp[p][mk][lower] != -1) return dp[p][mk][lower];

    int aux = mk;
    vi bits(DIG,0);
    int ind = 0;
    while (aux) bits[ind++] = aux%3, aux /= 3;

    if (!lower) {
        if (bits[decomp[p]] == 2) return dp[p][mk][lower] = 0;
        return dp[p][mk][lower] = solve(p-1, mk + pot3[decomp[p]], 0)*10 + decomp[p];
    }

    ll maxi = 0;
    dforn(i,DIG) {
        if (bits[i] == 2) continue;

        int newmk = mk + pot3[i];

        maxi = max(maxi, solve(p-1,newmk,1)*10 + i);
        if (i < decomp[p]) maxi = max(maxi, solve(p-1,newmk,0)*10 + i);
    }

    return dp[p][mk][lower] = maxi;
}

int main() {
    pot3[0] = 1;
    forsn(i,1,DIG) pot3[i] = pot3[i-1] * 3LL;

    ll u;
    while (scanf("%lld",&u) != -1) {
        decomp.clear();

        while (u) decomp.pb(u%10), u /= 10;
        reverse(all(decomp));

        n = (int)decomp.size();

        forn(i,MAXD) forn(j,MAXE) forn(k,2) dp[i][j][k] = -1;

        printf("%lld\n",max(solve(n-1,0,0),solve(n-1,0,1)));
    }
        
    return 0;
}
