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

const int MAXN = 4e5+5;
const int MAXC = 20;
const ll INF = 9e18;

int arr[MAXN];
ll invCol[MAXC][MAXC]; // si el color a es menor, inversiones con el color b siendo éste mayor
int cntCol[MAXC];
ll dp[1<<MAXC];

int main() {
    FAST_IO;

    forn(i,1<<MAXC) dp[i] = INF;

    int n; cin >> n;
    forn(i,n) cin >> arr[i], arr[i]--;

    forn(i,n) {
        forn(j,MAXC) 
            invCol[arr[i]][j] += cntCol[j];
        cntCol[arr[i]]++;
    }

    queue<int> Q;
    Q.push(0); dp[0] = 0;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        forn(i,MAXC) if (!(e&(1<<i))) {
            int act = e | (1<<i);
            ll r = dp[e];

            forn(j,MAXC) {
                if (!(act&(1<<j))) 
                    r += invCol[i][j]; // j > i
                else if (j != i) r += invCol[j][i]; // j < i
            }

            if (dp[act] == INF) Q.push(act);
            dp[act] = min(dp[act],r);
        }
    }

    cout << dp[(1<<20)-1] / 2LL;

    return 0;
}