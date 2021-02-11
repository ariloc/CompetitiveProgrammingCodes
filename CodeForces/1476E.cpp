#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;

struct trie {
    map<char,trie> edges;
    trie(){id = -1;}

    int id;

    void insert(const string &s, int myId, int i = 0) {
        if ((int)s.size() == i) id = myId;
        else edges[s[i]].insert(s,myId,i+1);
    }

    vi find (const string &s, int i = 0) { // max 16 pos 2^4 posib
        if ((int)s.size() == i) {
            if (id != -1) return {id};
            else {vi empt; return empt;}
        }
        vi r;
        if (edges.count(s[i])) {vi aux = edges[s[i]].find(s,i+1); for (auto &j : aux) r.pb(j);}
        if (edges.count('_')) {vi aux = edges['_'].find(s,i+1); for (auto &j : aux) r.pb(j);}
        return r;
    }
};

map<string,vi> patAux;
vector<string> patStr;
vi patInds[MAXN];
vector<pair<string,int>> req;
vi G[MAXN];
int ids[MAXN],typInd[MAXN],deg[MAXN];
trie T;

int main() {
    FAST_IO;
    memset(typInd,-1,sizeof(typInd));

    int n,m,k; cin >> n >> m >> k;
    forn(i,n) {
        string s; cin >> s;
        patAux[s].pb(i);
    }

    int idx = 0;
    for (auto &i : patAux) {patInds[idx] = i.snd; for (auto &j : i.snd) ids[j] = idx; idx++;}

    bool posib = true;
    map<string,int> lst;
    forn(j,m) {
        string s; int x; cin >> s >> x; x--;
        if (lst.count(s)) {
            if (lst[s] != x) return cout << "NO", 0; // string iguales no pueden pedir prioridades distintas
            continue;
        }
        lst[s] = x;
        if (typInd[ids[x]] == -1) typInd[ids[x]] = x;
        else if (typInd[ids[x]] != x) posib = false;

        req.pb({s,x});
    }

    if (!posib) return cout << "NO", 0; // dos strings llaman a dos patrones iguales, distintos ids

    idx = 0;
    for (auto &i : patAux) T.insert(i.fst,idx++), patStr.pb(i.fst);

    for (auto &i : req) {
        bool match = true;

        int myId = ids[i.snd];

        string tg = patStr[myId];
        forn(j,k)
            if (i.fst[j] != tg[j] && tg[j] != '_')
                {match = false; break;}


        if (!match) return cout << "NO", 0; // no será posible si siquiera el que quiero matchea

        vi toSet = T.find(i.fst);

        for (auto &j : toSet) {
            if (j == myId) continue;
            //cerr << i.fst << ' ' << j << ' ' << myId << ' ' << patStr[myId] << ' ' << patStr[j] << endl;
            G[myId].pb(j); deg[j]++;
        }
    }

    // pos por fin ahora un TopSort
    vi topSort;
    queue<int> Q;
    forn(j,idx) if (!deg[j]) Q.push(j);

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();
        topSort.pb(e);

        for (auto &i : G[e]) if (!(--deg[i])) Q.push(i);
    }

    if ((int)topSort.size() != idx) return cout << "NO", 0;
    else {
        cout << "YES\n";
        for (auto &i : topSort) {
            int shown = typInd[i];
            if (shown != -1) cout << shown+1 << ' ';
            for (auto &j : patInds[i]) if (j != shown) cout << j+1 << ' ';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
