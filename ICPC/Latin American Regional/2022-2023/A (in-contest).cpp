#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<bitset>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int const MAXN = 1005;

vi RG[MAXN], G[MAXN];
bitset<MAXN> done, reach, reachprv;

void dfs(int st, bool passed) {
    done[st] = true;
    if (!passed || reachprv[st]) reach[st] = true;

    for (auto &i : RG[st])
        if (!done[i])
            dfs(i, passed);
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x,y; cin >> x >> y; --x, --y;
        RG[x].pb(i), RG[y].pb(i);
        G[i].pb(x), G[i].pb(y);
    }

    forn(i,n) {
        forn(k,n) done[k] = false, reach[k] = reachprv[k] = false;
        done[i] = true; // ban
        dfs(G[i][0],0);

        swap(reach,reachprv);
        forn(k,n) done[k] = false;
        done[i] = true; // ban
        dfs(G[i][1],1);
        swap(reach,reachprv);

        bool posib = false;
        for (auto &j : RG[i]) {
            forn(k,n) done[k] = false, reach[k] = false;
            done[i] = true; // ban
            dfs(j,1);
            forn(k,n) if (reach[k]) {posib = true; break;}
        }

        cout << (posib ? "Y" : "N");
    }
    cout << '\n';

    return 0;
}
