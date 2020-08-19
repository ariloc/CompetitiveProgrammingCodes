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

const int MAXN = 1e5+2;
const int INF = 1e9+2;

vi G[MAXN];
vi D1(MAXN,INF),D2(MAXN,INF);
int rta = 0, d;

void bfs(int st, vi &D, bool save = false) {
    queue<int> Q; // ind, num
    D[st] = 0;
    Q.push(st);

    while (not Q.empty()) {
        int x = Q.front(); Q.pop();
        
        if (save) {
            int calc = D1[x] + D[x];
            if (calc <= d) rta++;
        }

        for (auto &i : G[x]) {
            if (D[i] != INF) continue;
            D[i] = D[x]+1;
            Q.push(i);
        }
    }
}

int main() {
    int N,M;
    scanf("%d %d %d",&N,&M,&d);

    forn (i,M) {
        int a,b;
        scanf("%d %d",&a,&b);
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs(0,D1);
    bfs(N-1,D2,true);

    printf("%d",rta);

    return 0;
}
