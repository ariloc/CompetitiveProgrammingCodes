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
const int INF = 1e9+2;
const int ops[3][2] = {{1,2},{0,2},{0,1}};

vi G[MAXN];
int types[MAXN]; // type -> A = 0 | B = 1 | C = 2
int typCnt[3];
bitset<MAXN> done;

void dfs (int st, int mask) {
    done[st] = true;

    forn (i,3) {
        bool bit = (mask & (1<<i));
        if (ops[i][bit] != types[st]) typCnt[i]++;
        mask ^= (1<<i);
    }

    for (auto &i : G[st]) if (!done[i]) dfs(i,mask);
}

int main() {
    freopen("repetidores.in","r",stdin);
    freopen("repetidores.out","w",stdout);

    int N; scanf("%d",&N);

    forn (i,N) {
        int x,m; char typ;
        scanf("%d %c %d",&x,&typ,&m);
        x--;

        types[x] = (typ-'A');

        forn (j,m) {
            int v; scanf("%d",&v);
            v--;
            G[x].pb(v);
            G[v].pb(x);
        }
    }

    int rta = INF, ind = 0;
    //int mask = 0;
    //forn (i,3) if (ops[i][1] == types[0]) mask |= (1<<i); // indice ref

    dfs(0,0);
    forn (i,3) {
        if (typCnt[i] < rta) {rta = typCnt[i]; ind = i;}
        typCnt[i] = 0;
    }
    done.reset();
    dfs(0,7);
    forn (i,3) {
        if (typCnt[i] < rta) {rta = typCnt[i]; ind = i;}
    }

    vector<char> toPrint;
    forn (i,3) if (i != ind) toPrint.pb('A'+i);

    printf("%d %c %c\n",rta,toPrint[0],toPrint[1]);
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
