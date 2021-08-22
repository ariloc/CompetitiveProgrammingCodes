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
bitset<MAXN> done;

int dfs(int st, int cnt) {
    done[st] = true;

    int val = 0;
    for (auto &i : G[st])
        if (!done[i]) val += dfs(i,cnt+1);

    return val + (!(cnt & 1));
}

int main() {
    FAST_IO;

    ll N; cin >> N;

    forn (i,N-1) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    int ind = -1;
    forn (i,N) if (G[i].size() == 1) {ind = i; break;}

    ll par = dfs(ind,1);
    //cerr << "OK";

    ll rta = par*(N-par);
    ll ari = 0;
    forn (i,N) ari += (ll)G[i].size();
    rta -= ari/2;

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!