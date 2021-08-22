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

const int MAXN = 105;
const int MAXNUM = 1e4+1;
const ll INF = 1e18+5;

int mat[MAXN][MAXN];

int main() {
    FAST_IO;

    int n,m,d; cin >> n >> m >> d;

    forn(i,n) forn(j,m) cin >> mat[i][j];

    ll mini = INF;
    forsn (k,1,MAXNUM) {
        ll myVal = 0;
        bool posib = true;
        forn(i,n) forn(j,m){
            if (abs(mat[i][j]-k) % d) {posib = false; break;}
            myVal += abs(mat[i][j]-k) / d;
        }
        if (!posib) continue;
        mini = min(mini,myVal);
    }

    if (mini == INF) cout << -1;
    else cout << mini;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!