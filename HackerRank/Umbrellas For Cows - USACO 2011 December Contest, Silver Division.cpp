// https://www.hackerrank.com/contests/simulacro-2-oia-2020/challenges/problem-3-umbrella/problem
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

const int MAXN = 5001;
const int MAXM = 1e5+2;
const int INF = 1e9+5;

int dp[MAXN],uppBoundCalc[MAXM];

int umbrellasForCows(int N, int M, vector <int> x, vector <int> c) {
    forn(i,MAXN) dp[i] = INF;
    sort(all(x));

    // precalculo posiciones corresp así saco el factor log (no hago upper_bound)
    int ind = 0;
    forn(i,MAXM) {
        if (ind < (int)x.size() && i >= x[ind]) ind++;
        uppBoundCalc[i] = (ind == (int)x.size() ? MAXN-1 : ind);
    }

    dp[0] = 0;
    forn(i,N) forn(j,M) {
        int nxt = uppBoundCalc[min(x[i]+j,MAXM-1)];
        dp[nxt] = min(dp[nxt],dp[i]+c[j]);
    }
    return dp[MAXN-1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector <int> x(N), c(M);
    for(int i=0; i<N; i++)
        cin >> x[i];

    for(int i=0; i<M; i++)
        cin >> c[i];

    cout << umbrellasForCows(N, M, x, c) << endl;

    return 0;
}
