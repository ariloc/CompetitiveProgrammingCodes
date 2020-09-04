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

const int MAXN = 505;
const ll INF = 1e18+5;

ll D[MAXN][MAXN];

int main() {
    FAST_IO;

    forn(i,MAXN) forn(j,MAXN) D[i][j] = INF;

    int n,m,q; cin >> n >> m >> q;

    forn (i,m) {
        int a,b; ll w; cin >> a >> b >> w; a--; b--;
        D[a][b] = min(D[a][b],w);
        D[b][a] = min(D[b][a],w);
    }

    forn (k,n) forn (i,n) forn(j,n)
        D[i][j] = min(D[i][j],D[i][k]+D[k][j]);

    forn(i,q) {
        int a,b; cin >> a >> b; a--; b--;
		if (a == b) {cout << "0\n"; continue;}
        cout << (D[a][b] == INF ? -1 : D[a][b]) << '\n';
    }

    return 0;
}
