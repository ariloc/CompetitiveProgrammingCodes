#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXL = 3e5+5;

struct item {
    string pal;
    int val;

    bool operator< (const item &o) const {
        return val > o.val;
    }
};

int prox_libre = 0;

struct trie {
    map<char, trie> edges;
    int id = -1;

    void insert (const string &s, vi &ids, int i = 0) {
        if (id == -1) id = prox_libre++;
        ids.pb(id);
        if (i < (int)s.size()) edges[s[i]].insert(s,ids,i+1);
    }
};

vector<item> elem[MAXL];

long long curry(vector<string> &palabras, vector<int> &significados) {
    forn(i,palabras.size())
        elem[(int)palabras[i].size()].pb({palabras[i], significados[i]});

    ll rta = 0;
    forsn(i,1,MAXL) {
        if (elem[i].empty()) continue;
        int n = (int)elem[i].size();
        trie T, T2;

        vector<item> &curr = elem[i];
        sort(all(curr));

        vector<vi> sufs(n), prefs(n);

        forn(j,n) {
            string aux = curr[j].pal;
            reverse(all(aux));
            T.insert(aux, sufs[j]);
            reverse(all(sufs[j]));
            sufs[j].pop_back();
        }

        forn(j,n){
            T2.insert(curr[j].pal, prefs[j]);
            prefs[j].erase(prefs[j].begin());
        }
        
        map<ii, pair<int,ll>> appear;
        forn(k,i) {
            appear.clear();
            forn(j,n) {
                ii par = {k-1 >= 0 ? prefs[j][k-1] : -1, k+1 < i ? sufs[j][k+1] : -1};
                auto it = appear.find(par);
                if (it != appear.end()) {
                    rta += (*it).snd.snd - (*it).snd.fst * (ll)curr[j].val;
                    (*it).snd.fst++, (*it).snd.snd += curr[j].val;
                }
                else appear[par] = {1, curr[j].val};
            }
        }
    }

    return rta;
}
