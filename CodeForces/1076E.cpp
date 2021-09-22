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

const int MAXN = 3e5+2;

vi tree[MAXN];
vector<ii> query[MAXN];
ll FT[MAXN], rta[MAXN];
bitset<MAXN> done;

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

ll getFT (int p) {
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void dfs (int st, int lvl) {
    done[st] = true;

    for (auto &i : query[st])
        {setFT(lvl,i.snd); setFT(lvl+i.fst+1,-i.snd);}

    rta[st] = getFT(lvl);
    for (auto &i : tree[st])
        if (!done[i]) dfs(i,lvl+1);

    for (auto &i : query[st])
        {setFT(lvl,-i.snd); setFT(lvl+i.fst+1,i.snd);}
}

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N-1) {
        int a,b; cin >> a >> b; a--; b--;
        tree[a].push_back(b); // formo el árbol
        tree[b].push_back(a);
    }

    int k; cin >> k;

    forn (i,k) {
        int v,d,x; cin >> v >> d >> x; v--;
        query[v].push_back({d,x}); // guardo por cada nodo las diferentes queries
    }

    dfs(0,1); // recorro el grafo en profundidad

    forn (i,N) cout << rta[i] << ' ';

    return 0;
}