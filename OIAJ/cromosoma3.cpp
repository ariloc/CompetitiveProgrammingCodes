#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

map<char,int> MAP = {{'A',0},{'C',1},{'G',2},{'T',3}};

int prox_libre = 0;
vector<vi> byId;

// Se puede con hashing, pero lo hacemos con Trie para que sea OIA-friendly
struct trie {
    unordered_map<int, trie> edges;
    int id = -1;

    void insert(vi &s, int idx, int i = 0) {
        if (i == sz(s)) {
            if (id == -1) id = prox_libre++, byId.pb({});
            byId[id].pb(idx);
        }
        else edges[s[i]].insert(s,idx,i+1);
    }
    int find (vi &s, int i = 0) {
        if (i == sz(s)) return id;
        if (!edges.count(s[i])) return -1;
        return edges[s[i]].find(s,i+1);
    }
};

trie T;

vector<int> cromosoma(string cadena) {
    vi cad;
    int n = sz(cadena);
    forn(i,n) cad.pb(MAP[cadena[i]]);

    forn(i,n) {
        vi histo(4,0);
        forsn(j,i,n) {
            histo[cad[j]]++;
            T.insert(histo,i);
        }
    }

    for (auto &i : byId) sort(all(i));

    vi allhisto(4,0);
    forn(i,n) allhisto[cad[i]]++;
    forn(k,4) {
        if (allhisto[k]&1) return {-1,-1,-1,-1};
        allhisto[k] /= 2;
    }

    forn(i,n) {
        vi ot = allhisto;
        forsn(j,i,n) {
            ot[cad[j]]--;
            int otidx = T.find(ot);
            int len = ot[0] + ot[1] + ot[2] + ot[3];
            if (otidx != -1) {
                auto it = lower_bound(all(byId[otidx]),j+1);
                int val;
                if (it != byId[otidx].end() && (val = *it) <= i+n-len) {
                    vi tent = {i,(j+1)%n,val%n,(val+len)%n};
                    unordered_set<int> idx = {tent[0],tent[1],tent[2],tent[3]};
                    for (int l = tent[1]; l != tent[2] && sz(idx) < 4; l=(l+1)%n)
                        idx.insert(l);
                    for (int l = tent[3]; l != tent[0] && sz(idx) < 4; l=(l+1)%n)
                        idx.insert(l);
                    if (sz(idx) == 4) {
                        vi auxi;
                        for (auto &l : idx) auxi.pb(l);
                        return auxi;
                    }
                }
            }
        }
    }

    return {-1,-1,-1,-1};
}
