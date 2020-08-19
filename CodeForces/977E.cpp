#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+2;

vi G[MAXN];
bitset<MAXN> done;

bool dfs (int st, int &orig) {
    done[st] = true;

    bool retVal = 1;
    if (G[st].size() != 2) retVal = 0;
    bool toSt = false; bool pass = false;
    for (auto &i : G[st])
        if (!done[i])
            {bool v = dfs(i,orig); if (retVal) retVal = v; pass = true;}
        else if (i == orig) toSt = true;

    if (!toSt and !pass) retVal = 0;

    return retVal;
}

int main() {
    FAST_IO;

    int N,m; cin >> N >> m;
    forn (i,m) {
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    int cycle = 0;

    forn (i,N)
        if (!done[i])
            if (dfs(i,i)) cycle++;

    cout << cycle;

    return 0;
}