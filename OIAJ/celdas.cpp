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
typedef long double ld;

const int MAXN = 10005;
const string posib = "+-*";

int prox_hoja = 0, prox_nodo = 0;
int nodoOrd[MAXN], inDeg[MAXN], nodoHoja[MAXN];
bitset<MAXN> inHoja[MAXN];
unordered_map<string,int> hojas;
unordered_map<string,int> cells;
vi G[MAXN];
bitset<MAXN> dp[MAXN];
bitset<MAXN> done;

void dfs (int st) {
    done[st] = true;
    for (auto &i : G[st]) {
        if (!done[i]) dfs(i);
        dp[st] |= dp[i];
        dp[st][i] = true;
    }
}

int parseCell (string &x, int l) {
    int exclam = x.find('!', l);

    int nd = exclam;
    string strhoja = "";
    forsn(i,exclam+1,x.size())
        if (x[i] >= 'A' && x[i] <= 'Z') 
            strhoja.pb(x[i]), nd = i;
        else break;

    string strid = x.substr(l, nd-l+1);
    int numid = -1;

    auto it = cells.find(strid);
    if (it == cells.end()) {
        numid = cells[strid] = prox_nodo++;

        int numhoja = -1;
        auto it2 = hojas.find(strhoja);
        if (it2 == hojas.end())
            numhoja = hojas[strhoja] = prox_hoja++;
        else numhoja = (*it2).snd;

        inHoja[numhoja][numid] = true;
        nodoHoja[numid] = numhoja;
    }
    else numid = (*it).snd;

    return numid;
}
 
void celdas(vector <string> &c, vector <int> &celdasTotal, vector <int> &celdasMismaHoja) {
    int n = (int)c.size();
    forn(i,n) {
        int eqsep = c[i].find('=');
        int me = parseCell(c[i], 0);
        nodoOrd[me] = i;

        vi ady;
        string::iterator it = c[i].begin()+eqsep;
        while (it != c[i].end()) {
            it++;
            if (*it >= 'A' && *it <= 'Z')
                ady.pb(parseCell(c[i], it - c[i].begin()));
            it = find_first_of(it, c[i].end(), posib.begin(), posib.end());
        }

        for (auto &j : ady)
            G[j].pb(me), inDeg[me]++;
    }

    vi rta1(n,0), rta2(n,0);
    forn(i,prox_nodo) if (!inDeg[i]) dfs(i);
    forn(i,prox_nodo) {
        int a = nodoOrd[i];
        rta1[a] += dp[i].count();
        rta2[a] += (dp[i] & inHoja[nodoHoja[i]]).count();
    }

    celdasTotal = rta1;
    celdasMismaHoja = rta2;
}
