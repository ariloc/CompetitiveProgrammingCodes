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

const int MAXN = 1002;

vi G[MAXN];
int D1[MAXN],D2[MAXN];
bool connected[MAXN][MAXN];

void bfsAll(int st, int *D) {
    queue<ii> Q;
    Q.push({st,0});
    D[st] = 0;

    while (not Q.empty()) {
        ii e = Q.front(); Q.pop();

        for (auto &i : G[e.fst]) {
            if (D[i] != -1) continue;
            D[i] = e.snd+1;

            Q.push({i,D[i]});
        }
    }
}

int main() {
    FAST_IO;
    memset(D1,-1,sizeof(D1));
    memset(D2,-1,sizeof(D2));

    int n,m,s,t; cin >> n >> m >> s >> t; s--; t--;

    forn (i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        connected[a][b] = true;
        connected[b][a] = true;
    }

    bfsAll(s,D1); // camino original
    int distTop = D1[t];

    bfsAll(t,D2); // distancias de final a otros nodos

    int cnt = 0;
    forn (i,n)
        forsn (j,i+1,n) {
            if (connected[i][j]) continue;
            if ( min(D1[i]+D2[j]+1, D1[j]+D2[i]+1) >= distTop )
                cnt++;
        }

    cout << cnt;

    return 0;
}