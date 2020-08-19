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

const int MAXN = 5001;

vi G[MAXN], orden;
bitset<MAXN> done;

int dfs (int st) {
    done[st] = true;
    for (auto &i : G[st])
        if (!done[i])
            dfs(i);

    orden.push_back(st);
}

int reachable (int st) {
    done[st] = true;
    for(auto &i : G[st])
        if (!done[i])
            reachable(i);
}

int discard (int st) {
    done[st] = true;
    for (auto &i : G[st])
        if (!done[i])
            discard(i);
}

int main() {
    FAST_IO;

    int n,m,s,r = 0;
    cin >> n >> m >> s;

    forn (i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }

    reachable(s-1);

    forn (i,n) {
        if (done[i]) continue;
        dfs(i);
    }

    reverse(all(orden));
    done.reset();

    for (auto &i : orden) {
        if (done[i]) continue;
        discard(i);
        r++;
    }

    cout << r;

    return 0;
}