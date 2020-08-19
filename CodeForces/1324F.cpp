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

const int MAXN = 2e5+2;
const int INF = 1e9+2;

int best[MAXN];
bitset<MAXN> white; // true is white, false is black
bitset<MAXN> done;
vi G[MAXN];

void bfsAdd (int st) {
    queue<int> Q;
    Q.push(st);
    done[st] = true;

    while (not Q.empty()) {
        int e = Q.front(); Q.pop();

        for (auto &i : G[e]) {
            if (done[i]) continue;
            done[i] = true;
            best[i] += max(0,best[e]-(best[i] <= 0 ? 0 : best[i]));
            Q.push(i);
        }
    }
}

int dfs (int st) {
    int r = 0;
    done[st] = true;

    for (auto &i : G[st]) {
        if (done[i]) continue;
        int toAdd = max(0,dfs(i));
        r += toAdd;
    }

    return best[st] = r + (white[st] ? 1 : -1);
}

int main() {
    FAST_IO;
    memset(best,-1,sizeof(best));

    int N;
    cin >> N;

    forn (i,N) {
        int x; cin >> x; white[i] = x;
    }

    forn (i,N-1) {
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0); done.reset(); bfsAdd(0);

    forn (i,N) cout << best[i] << ' ';

    return 0;
}