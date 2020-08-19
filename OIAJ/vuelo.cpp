#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXM = 4e4+2;
const ll INF = 1e12+5;
const int MAXD = 301;

int vuelo[MAXM];
ll dp[MAXM][MAXD];
int S[MAXM][MAXD];
int N;

ll solve(int act, int H) {
    if (H < 0) return INF;
    if (dp[act][H]) return dp[act][H];
    if (act == N+1) return 1;
    dp[act][H] = min(solve(act+1,H+1),solve(act+1,H-1)) + abs(H-vuelo[act]);
    ll U = solve(act+1,H+1),D = solve(act+1,H-1);
    if (min(U,D) == U)
        S[act][H] = H+1;
    else S[act][H] = H-1;
    return dp[act][H];
}

int main() {
    freopen("vuelo.in","r",stdin);
    freopen("vuelo.out","w",stdout);

    scanf("%d",&N);

    vuelo[0] = 0;
    forn (i,N) {
        int x;
        scanf("%d",&x);
        vuelo[i+1] = x;
    }

    printf("%lld\n",solve(0,0)-1);
    int act = 1;
    for (int i = 1; i != -1 and i != 0; i = S[act++][i])
        printf("%d\n",i);

    return 0;
}
