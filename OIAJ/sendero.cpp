#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const INF = 2e9+10;
int const MAXA = 26;
int const MAXN = 2e6;
int const MAP[] = {'B', 'G', 'N'};

int dp[MAXN][3];
int P[MAXN][3];

int sendero(int B, int G, int N, string &s) {
    int n = (int)s.size();
    int costs[] = {B,G,N};

    forn(i,n) forn(k,3) dp[i][k] = INF, P[i][k] = -1;

    forn(i,3) if (s[0] == 'R') dp[0][i] = costs[i];
    forn(i,3) if (s[0] == MAP[i]) dp[0][i] = 0;
    forsn(i,1,n) {
        if (s[i] == 'R') {
            forn(j,3) forn(k,3) {
                if (j == k) continue;
                int cost = dp[i-1][j] + costs[k];
                if (cost < dp[i][k]) {
                    dp[i][k] = cost;
                    P[i][k] = j;
                }
            }
        }
        else {
            forn(j,3) {
                int ind = s[i] == 'B' ? 0 : s[i] == 'G' ? 1 : 2;
                if (j == ind) continue;
                if (dp[i-1][j] < dp[i][ind]) {
                    dp[i][ind] = dp[i-1][j];
                    P[i][ind] = j;
                }
            }
        }
    }

    int mini = INF, ind;
    forn(k,3) if (dp[n-1][k] < mini) mini = dp[n-1][k], ind = k;

    string auxi;
    int j = n-1;
    while (j >= 0) {
        auxi.pb(MAP[ind]);
        ind = P[j][ind];
        --j;
    }
    reverse(all(auxi));
    swap(s,auxi);

    return mini;
}
