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

const int MAXN = 252;
const int INF = 1e9+5;

ii office[MAXN];
int dp[MAXN][MAXN], sumT[MAXN][MAXN], S[MAXN][MAXN];

int solve (int l, int r) {
    if (dp[l][r] != -1) return dp[l][r]; // lo ya guardado
    if (r-l == 1) {
        S[l][r] = l;
        return sumT[l][r] = dp[l][r] = office[l].snd; // caso base
    }
    int mini = INF, ind = 0;
    forsn(mid,l,r) { // rangos
        int sum = solve(l,mid) + solve(mid+1,r); // [l,mid) [mid+1,r)
        if (sum < mini) { // que sea lo más chico lo acumulado
            mini = sum;
            ind = mid;
        }
    }
    int me = sumT[l][ind] + sumT[ind+1][r] + office[ind].snd;
    sumT[l][r] = me; // mi nueva parte original
    S[l][r] = ind; // sucesores
    return dp[l][r] = me+mini; // mi nuevo valor hasta acá
}

void dfs(int l, int r) {
    if (r <= l) return;
    putchar('(');
    int mid = S[l][r];
    dfs(l,mid);
    printf("%d",office[mid].fst);
    dfs(mid+1,r);
    putchar(')');
}

int main() {
    freopen("oficinas.in","r",stdin);
    freopen("oficinas.out","w",stdout);
    int n; scanf("%d",&n);

    forn(i,n) scanf("%d %d",&office[i].fst,&office[i].snd);
    forn(i,n+1) forsn(j,i+1,n+1) dp[i][j] = -1; // reset
    sort(office,office+n);

    printf("%d\n",solve(0,n));
    dfs(0,n);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
