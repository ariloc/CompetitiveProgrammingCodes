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

const int MAXN = 2e5+2;

struct node {
    int v,h,p; // vertice, hijos, padres
};

vi G[MAXN];
vector<node> nodes;
bitset<MAXN> done, done2, industry;

int findLeaves (int st, int lvl) {
    done[st] = true;

    int down = 0;
    for (auto &i : G[st])
        if (!done[i])
            down += findLeaves(i,lvl+1);

    nodes.pb({st,down,lvl});

    return down+1;
}

ll rta = 0;

int calcMax (int st) {
    done2[st] = true;

    int down = 0;
    for (auto &i : G[st])
        if (!done2[i])
            down += calcMax(i);

    rta += (industry[st] ? 0 : down);

    return down + (industry[st] ? 1 : 0);
}

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    forn (i,n-1) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    findLeaves(0,0);
    sort(all(nodes),[](const node &a, const node &b)
         {if ((a.p-a.h) == (b.p-b.h)) return a.h < b.h;
              return (a.p-a.h) > (b.p-b.h);});

    forn (i,k)
        industry[nodes[i].v] = true;

    calcMax(0);

    cout << rta;

    return 0;
}