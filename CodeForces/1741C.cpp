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

const int MAXN = 2005;
const int INF = 2e9+5;

int arr[MAXN];
int dp[MAXN];
map<int,int> sums[MAXN];

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);

        forn(i,n+2) dp[i] = 0, sums[i].clear();

        forn(i,n) scanf("%d",&arr[i]);
        forn(i,n) dp[i+1] = dp[i] + arr[i];

        forsn(i,1,n+1) sums[i][dp[i]] = i;

        forsn(i,2,n+1) {
            forsn(j,i,n+1) {
                int act = dp[j] - dp[i-1];
                auto it = sums[i-1].find(act);
                if (it != sums[i-1].end()) {
                    auto it2 = sums[j].find(act);
                    int thick = INF;
                    if (it2 != sums[j].end()) thick = (*it2).snd;
                    sums[j][act] = min(thick, max((*it).snd, j-i+1));
                }
            }
        }

        int mini = INF;
        for (auto &i : sums[n])
            mini = min(mini, i.snd);

        printf("%d\n",mini);
    }

    return 0;
}
