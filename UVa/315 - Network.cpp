#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 10005;

struct edges {
    int v,id;
};

vector<edges> G[MAXN];
bitset<MAXN> matched, done_aux;
int comps_isin[MAXN];
vector<ii> inp;
int tin[MAXN], actT = 1;

vi pila;
int tarjan (int st) {
    tin[st] = actT++;

    int mini = tin[st];
    for (auto &i : G[st]) {
        if (!matched[i.id]) {
            int myMini = tin[st];
            pila.pb(i.id);
            matched[i.id] = true;

            if (!tin[i.v]) myMini = min(myMini, tarjan(i.v));
            myMini = min(myMini, tin[i.v]);

            if (myMini >= tin[st]) {
                vi nodes;
                while (!pila.empty()) {
                    auto e = pila.back(); pila.pop_back();
                    int exts[] = {inp[e].fst, inp[e].snd};
                    forn(k,2)
                        if (!done_aux[exts[k]])
                            done_aux[exts[k]] = true, nodes.pb(exts[k]);

                    if (e == i.id) break;
                }

                for (auto &j : nodes)
                    comps_isin[j]++, done_aux[j] = 0;
            }

            mini = min(mini,myMini);
        }
    }

    return mini;
}

int main() {
    FAST_IO;

    int n;
    while (cin >> n) {
        if (!n) break;

        inp.clear(); actT = 1;
        forn(i,n) G[i].clear(), tin[i] = comps_isin[i] = 0;
        matched.reset();

        cin.ignore(20,'\n');
        forn(i,n+1) {
            string s; getline(cin,s);
            stringstream ss; ss << s;
            int x; ss >> x;
            if (!x) break;
            x--;
            while (ss) {
                int y; ss >> y; y--;
                if (!ss) break;
                G[y].pb({x,(int)inp.size()}), G[x].pb({y,(int)inp.size()});
                inp.pb({x,y});
            }
        }

        tarjan(0);

        int arts = 0;
        forn(i,n) if (comps_isin[i] > 1) arts++;

        cout << arts << '\n';
    }

    return 0;
}
