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

const int MAXN = 52;
const int INF = 5e5+2;

int TAd[MAXN][MAXN];

void tablaAditiva() {
    forn(i,MAXN) {
        int cnt = 0;
        forn(j,MAXN) {
            if (i+1 < MAXN) TAd[i+1][j] += TAd[i][j];
            cnt += TAd[i][j];
            TAd[i][j] = cnt;
        }
    }
}

int main() {
    FAST_IO;

    int N,M;
    cin >> N >> M;

    forn (i,N) {
        forn (j,M) {
            int x;
            cin >> x;
            TAd[i+1][j+1] = x;
        }
    }

    tablaAditiva();

    int r = -INF;
    forn (i,N+1)
        forn (j,M+1)
            forn(k,i)
                forn(l,j) {
                    r = max((TAd[i][j] + TAd[k][l] - TAd[i][l] - TAd[k][j]),r);
                }

    cout << r;

    return 0;
}
