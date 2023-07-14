// https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14
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

const int MAXL = 8005;
const int MAXG = 805;
const ll INF = 1e18;

ll cell[MAXL], tad[MAXL];
ll dp[2][MAXL];

ll cost (int l, int r) {
    if (l > r) swap(r,l);
    return (r-l+1)*(tad[r+1]-tad[l]);
}

int solve_row (int l, int lr, int rr, bool k) {
    ll mini = INF; int ind = -1;
    forsn(r,lr,rr) {
        ll aux = cost(l,r) + dp[1^k][r+1];
        if (aux < mini) mini = aux, ind = r;
    }
    dp[k][l] = mini;
    return ind;
}

void divide (int ll, int rl, int lr, int rr, bool k) {
    if (rl-ll < 1) return;

    int mid = (ll+rl)/2;
    int opt_ind = solve_row(mid,lr,rr,k);
    divide(ll,mid,lr,opt_ind+1,k);
    divide(mid+1,rl,opt_ind,rr,k);
}

int main() {
    int L,G; scanf("%d %d",&L,&G);

    forn(i,L) scanf("%lld",&cell[i]);

    forn(i,L+5) tad[i+1] = tad[i]+cell[i];

    ll rta = INF;
    forn(i,L) dp[0][i] = INF;
    forsn(i,1,G+1) {
        forn(j,L+5) dp[i&1][j] = INF;
        divide(0,L,0,L,i&1);
        rta = min(rta,dp[G&1][0]);
    }

    printf("%lld",rta);
           
    return 0;
}
