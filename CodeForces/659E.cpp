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

const int MAXN = 1e5+5;

vi G[MAXN];
bitset<MAXN> done, reached;
int tmpAc = -1, nd = -1, cnt = 0;

void dfs(int st, int accum) {
    done[st] = true;
    if (accum > tmpAc) {tmpAc = accum; nd = st;}

    for (auto &i : G[st])
        if (!done[i])
            dfs(i,accum + 1);
}

void dfs2 (int st, int &prim, int prev) {
    done[st] = true;

    for (auto &i : G[st])
        if (!done[i])
            dfs2(i,prim,st);
        else if (prev != i and done[prim])
            if (!reached[prim]) {reached[prim] = true; cnt++;}

    if (st != prim) {
        if (!reached[st]) {reached[st] = true; cnt++;}
    }
}

int main() {
    FAST_IO;

    int n,m;
    cin >> n >> m;

    forn (i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    forn (i,n) {
        if (reached[i]) continue;
        dfs2(i,i,i);
        done.reset();
        tmpAc = nd = -1;
    }

    cout << n-cnt;

    return 0;
}