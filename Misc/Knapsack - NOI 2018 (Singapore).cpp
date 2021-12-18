// https://oj.uz/problem/view/NOI18_knapsack
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

const int MAXN = 1e5+5;
const int MAXW = 2005;
const ll INF = 9e18;

struct state {
    ll bst;
    int cnt_last,last;
};

struct item {
    int v,w,k;

    bool operator< (const item &o) const {
        return (double)v/w > (double)o.v/o.w;
    }
};

item types[MAXN];
state dp[MAXW];

int main() {
    int S,N; scanf("%d %d",&S,&N);

    forn(i,N) scanf("%d %d %d",&types[i].v,&types[i].w,&types[i].k);
    sort(types,types+N);

    forn(i,S+1) dp[i] = {-INF,0,-1};
    dp[0] = {0,0,-1};

    forn(i,N) {
        ll v = types[i].v;
        int w = types[i].w, k = types[i].k;
        forsn(j,w,S+1) {
            ll val = dp[j-w].bst + v;
            if (val > dp[j].bst && (dp[j-w].last != i || dp[j-w].cnt_last < k))
                dp[j] = {val, (dp[j-w].last != i ? 1 : dp[j-w].cnt_last + 1), i};
        }
    }

    forsn(i,1,S+1) dp[i].bst = max(dp[i].bst, dp[i-1].bst);

    printf("%lld",dp[S].bst);
    
    return 0;
}