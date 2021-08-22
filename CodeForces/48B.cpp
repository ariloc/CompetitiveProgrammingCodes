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

const int MAXN = 55;
const int INF = 1e9+5;

int TAd[MAXN][MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn(i,n) forn(j,m) cin >>TAd[i+1][j+1];

    int a,b; cin >> a >> b;

    int cnt = 0;
    forn(i,n+1) forn(j,m+1) {
        cnt += TAd[i][j];
        TAd[i+1][j] += TAd[i][j];
        TAd[i][j] = cnt;
    }

    int mini = INF;
    forsn(i,1,n-a+2) forsn(j,1,m-b+2)
        mini = min(mini,TAd[i+a-1][j+b-1] + TAd[i-1][j-1] - TAd[i-1][j+b-1] - TAd[i+a-1][j-1]);

    //forn(i,n){ forn(j,m) cout << TAd[i][j] << ' '; cout << endl;}

    forsn(i,1,n-b+2) forsn(j,1,m-a+2)
        mini = min(mini,TAd[i+b-1][j+a-1] + TAd[i-1][j-1] - TAd[i-1][j+a-1] - TAd[i+b-1][j-1]);

    cout << mini;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!