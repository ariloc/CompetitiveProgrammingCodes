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

const int MAXN = 4002;

void fs(int &x) {
    int c; x = 0;
    while ((c=getchar_unlocked())<'0' || c>'9');
    for (;c>='0'&c<='9';c=getchar_unlocked())
        x = 10*x + c-'0';
}

struct sq {
    ii coords; int l;
};

bool block[MAXN][MAXN];
int dp[MAXN][MAXN];
sq row[MAXN],col[MAXN];

int main() {
    freopen("yurumi.in","r",stdin);
    freopen("yurumi.out","w",stdout);
    int M,N,X; fs(M); fs(N); fs(X);

    forn(i,X) {
        int y,x; fs(y); fs(x); y--; x--;
        block[y][x] = true;
    }

    dforn(i,M) dforn(j,N) if (!block[i][j])
        dp[i][j] = min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]})+1;

    int maxi = 0; ii maxiCoords = {-1,-1};
    dforn(i,M) {
        dforn(j,N) if (dp[i][j] > maxi) {maxi = dp[i][j]; maxiCoords = {i,j};}
        row[i] = {maxiCoords,maxi};
    }

    maxi = 0; maxiCoords = {-1,-1};
    dforn(j,N) {
        dforn(i,M) if (dp[i][j] > maxi) {maxi = dp[i][j]; maxiCoords = {i,j};}
        col[j] = {maxiCoords,maxi};
    }

    ii a = {-1,-1}, b = {-1,-1}; int Ba = -1, Bb = -1;
    int maxSup = 0;
    forn(i,M) forn(j,N) {
        int k = dp[i][j]; sq el;
        if (!k) continue;

        el = (row[i+k].l > col[j+k].l ? row[i+k] : col[j+k]);
        int sum = k*k + el.l*el.l;

        if (el.coords.fst == -1) continue;

        if (sum > maxSup) {
            maxSup = sum; Ba = k; Bb = el.l;
            a = {i,j}; b = el.coords;
        }
    }

    printf("%d %d %d\n%d %d %d",a.fst,a.snd,Ba,b.fst,b.snd,Bb);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
