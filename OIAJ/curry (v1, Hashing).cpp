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
const int p2 = 112345687;
const int MOD = 1e9+9;

struct item {
    string pal;
    int val;

    bool operator< (const item &o) const {
        return val > o.val;
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

        vector<item> &curr = elem[i];
        sort(all(curr));

        vector<vi> sufs(n, vi(i+1, 0));
        vi prefs(n,0);

        forn(j,n) {
            int mhash = 0, pow = 1;
            dforn(k,i) {
                mhash = (mhash + ((curr[j].pal[k] * (ll)pow)%MOD))%MOD;
                sufs[j][k] = mhash;
                pow = ((ll)pow * p2)%MOD;
            }
        }

        map<ii,pair<int,ll>> hashes;
        int pow = 1;

        forn(k,i) {
            pow = ((ll)pow * p2)%MOD;
            hashes.clear();

            forn(j,n) {
                if (k-1 >= 0) prefs[j] = (prefs[j] + ((curr[j].pal[k-1] * (ll)pow)%MOD))%MOD;

                ii act = {prefs[j], sufs[j][k+1]};
                auto it = hashes.find(act);
                if (it != hashes.end()) {
                    // cerr << curr[j].pal << ' ' << k << ' ' << (*it).snd.snd << ' ' << j << endl;
                    rta += (*it).snd.snd - (ll)((*it).snd.fst * (ll)curr[j].val);
                    (*it).snd.fst++;
                    (*it).snd.snd += curr[j].val;
                }
                else hashes[act] = {1, curr[j].val};
            }
        }
    }

    return rta;
}
