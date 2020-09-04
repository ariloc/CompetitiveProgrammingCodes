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

const int MAXN = 251;
const int INF = 1e9+5;

ii office[MAXN];
int dp[MAXN][MAXN], sumT[MAXN][MAXN], S[MAXN][MAXN];

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

    sort(office,office+n);

    forn(i,n+1) forsn(j,i+1,n+1) dp[i][j] = -1; // implica dp[i][i] = 0, otro caso base
    forn(i,n) {
        dp[i][i+1] = sumT[i][i+1] = office[i].snd; // caso base
        S[i][i+1] = i; // me voy a sí mismo así en el DFS queda (r == l) y corto
    }

    forsn(i,2,n+1) { // ancho ventana
        forn(j,n-i+1) { // tope ventana
            int l = j, r = j+i; // ventana
            int mini = INF, ind;
            forsn(mid,l,r) { // rangos en medio al partir
                int sum = dp[l][mid] + dp[mid+1][r]; // el que menos suma siguiente tiene
                if (sum < mini) {
                    mini = sum;
                    ind = mid;
                }
            }
            int me = sumT[l][ind] + sumT[ind+1][r] + office[ind].snd;
            dp[l][r] = mini + me; // mi nuevo valor suma
            sumT[l][r] = me; // mi nuevo valor en rango
            S[l][r] = ind; // mi nuevo sucesor
        }
    }

    printf("%d\n",dp[0][n]);
    dfs(0,n);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
