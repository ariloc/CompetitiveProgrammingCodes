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

const int MAXN = 402;

vi G[MAXN];
bool block[MAXN][MAXN];
bitset<MAXN> done;
int n,m;

int bfs(int st) {
    queue<ii> Q;
    Q.push({st,0});
    done[st] = true;

    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.fst == n-1)
            return e.snd;

        for (auto &i : G[e.fst]) {
            if (done[i]) continue;
            done[i] = true;
            Q.push({i,e.snd+1});
        }
    }
    return -1;
}

int main() {
    FAST_IO;

    cin >> n >> m;

    forn (i,m) {
        int a,b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        block[a][b] = true;
        block[b][a] = true;
    }

    int rail = bfs(0); done.reset();

    queue<ii> Q;
    Q.push({0,0});
    done[0] = true;

    int bus = -1;
    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.fst == n-1) {bus = e.snd; break;}

        forn (i,n) {
            if (done[i]) continue;
            if (i == e.fst) continue;
            if (block[e.fst][i]) continue;
            done[i] = true;

            Q.push({i,e.snd+1});
        }
    }

    if (rail == -1 or bus == -1) cout << -1;
    else cout << max(rail,bus);

    return 0;
}