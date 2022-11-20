#include <algorithm>
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

const int MAXN = 1e5+5;
const int MAXI = 105;
const int INF = 2e9;

ll dp[MAXN];
ii items[MAXN];

int main() {
    int n,w; scanf("%d %d", &n, &w);
    forn(i,n) scanf("%d %d", &items[i].fst, &items[i].snd);

    forsn(i,1,MAXN) dp[i] = INF;

    forn(i,n) dforsn(j,items[i].snd,MAXN)
        dp[j] = min(dp[j], dp[j-items[i].snd] + items[i].fst);

    int rta = 0;
    forn(i,MAXN) if (dp[i] <= w) rta = i;

    printf("%d", rta);
 
    return 0;
}

