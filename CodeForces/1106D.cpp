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

const int MAXN = 1e5+2;

vi G[MAXN];
vi camino;
bitset<MAXN> done;

void bfs(int st) {
    priority_queue<int, vi, greater<int> > Q;
    Q.push(st);
    done[st] = true;

    while (not Q.empty()) {
        int e = Q.top(); Q.pop();

        camino.push_back(e);

        for (auto &i : G[e])
            if (!done[i]) {
                done[i] = true;
                Q.push(i);
            }
    }
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,m) {
        int a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs(1);

    for (auto &i : camino) cout << i << ' ';

    return 0;
}