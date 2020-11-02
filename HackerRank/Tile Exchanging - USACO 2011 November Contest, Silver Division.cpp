// https://www.hackerrank.com/contests/simulacro-1-oia-2020/challenges/problem-3-tile-exchanging/problem
#include <bits/stdc++.h>

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

const int MAXN = 1e4+5;
const int MAX = 100;
const int MAXV = 12;
const int INF = 1e9+5;

int dp[MAXV][MAXN];

int tile_exchanging(int M, vector <int> A) {
    vector<ii> vals; // costo | peso (lo que sumo de sup)
    forn(i,MAXV) forn(j,MAXN) dp[i][j] = INF;
    dp[0][0] = 0;
    forn(i,A.size()) {
        forn(val,MAX+1) {
            int cost = (val-A[i])*(val-A[i]);
            forsn(area,val*val,MAXN) {
                dp[i+1][area] = min(dp[i+1][area],dp[i][area-(val*val)]+cost);
            }
        }
    }
    return dp[(int)A.size()][M] == INF ? -1 : dp[(int)A.size()][M];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector <int> a(N);
    for(int i=0; i<N; i++)
        cin >> a[i];

    cout << tile_exchanging(M, a) << endl;

    return 0;
}
