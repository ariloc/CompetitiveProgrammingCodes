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
const int MAXM = 2e5+2;
const int INF = 1e9+5;

struct DS {
    vi p,r;

    void init(int N) {
        p.assign(N,-1);
        r.assign(N,-1);
    }
    int find(int x) {return (p[x] == -1 ? x : p[x] = find(p[x]));}
    bool isSameSet(int a, int b) {return (find(a) == find(b));}
    void join (int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return;
        if (r[x] > r[y]) p[y] = x;
        else {
            p[x] = y;
            if (r[x] == r[y]) r[y]++;
        }
    }
};

vi volt, G[MAXN];
bitset<MAXN> done,comp,volunt;
int marked[MAXN];
DS UF;

int main() {
    FAST_IO;

    UF.init(MAXN-1);
    int n,m,k; cin >> n >> m >> k;

    forn (i,k) {int x; cin >> x; volt.pb(x-1); volunt[x-1] = true;}

    forn (i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    int s,t; cin >> s >> t; s--; t--;
    if (!volunt[t]) volt.pb(t);

    queue<int> Q[2];

    for (auto &i : volt) {Q[0].push(i); done[i] = true; marked[i] = -1;}

    int ind = 0, dist = 0, rta = -1;
    while (not Q[0].empty() or not Q[1].empty()) {
        vector<ii> waitToJoin;
        while (not Q[ind].empty()) {
            auto e = Q[ind].front(); Q[ind].pop();

            for (auto &i : G[e]) {
                //cerr << e+1 << ' ' << i+1 << ' ' << ind << ' ' << dist << endl;
                if (UF.isSameSet(s,t)) {
                        //cerr << e+1 << ' ' << i+1 << ' ' << ind << ' ' << dist << ' ' << odd << endl;
                    rta = ((dist+1)*2)-1; //considerando siempre impares primero
                    queue<int> empt1, empt2;
                    swap(Q[0],empt1); swap(Q[1],empt2);
                    break;
                }


                if (done[i]) {
                    if (!comp[i]) {
                        if (marked[i] == dist and marked[i] != -1) waitToJoin.pb({e,i});
                        else {UF.join(e,i);comp[i] = true;}
                    } else UF.join(e,i);
                    continue;
                }
                UF.join(e,i);

                done[i] = true; marked[i] = dist;
                Q[(ind+1)%2].push(i);
            }
        }
        for (auto &i : waitToJoin) UF.join(i.fst,i.snd);
        if (UF.isSameSet(s,t) and rta == -1) {rta = (dist+1)*2; break;}
        ind = (ind+1)%2; dist++;
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!