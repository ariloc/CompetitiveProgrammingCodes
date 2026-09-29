#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

int const MAXN = 1005;
int const MAXP = 5e5+5;

int deg[MAXN];
int ar1[MAXP], ar2[MAXP];
bitset<MAXN> done;
vi G[MAXN];
int seen = 0;

void dfs (int st) {
    done[st] = true;
    seen++;

    for (auto &i : G[st])
        if (!done[i]) dfs(i);
}

int main() {
    FAST_IO;

    int n; cin >> n;

    int a; cin >> a;
    forn(i,a) cin >> ar1[i], --ar1[i];
    int b; cin >> b;
    forn(i,b) cin >> ar2[i], --ar2[i];

    bool posib = true;

    set<ii> pairs;

    forn(i,n) forsn(j,i+1,n) deg[i]++, deg[j]++, pairs.insert({i,j});
    forsn(i,1,a) {
        int x = ar1[i-1], y = ar1[i];
        deg[x]--, deg[y]--;
        if (x > y) swap(x,y);
        auto it = pairs.find({x,y});
        if (it != pairs.end()) pairs.erase(it);
        if (x == y) posib = false;
    }

    forn(i,b-1) {
        int x = ar2[i], y = ar2[i+1];
        deg[x]--, deg[y]--;
        if (x > y) swap(x,y);
        auto it = pairs.find({x,y});
        if (it != pairs.end()) pairs.erase(it);
        if (x == y) posib = false;
    }

    if (!posib)
        return cout << "N\n", 0;

    forn(i,n) if (deg[i] < 0) return cout << "N\n", 0;

    for (auto &i : pairs) G[i.fst].pb(i.snd), G[i.snd].pb(i.fst);

    int on = -1, allpend = 0;
    forn(i,n) if (deg[i] != 0) allpend++, on = i;
    if (on != -1) {
        dfs(on);
        if (seen != allpend)
            return cout << "N\n", 0;
    }

    if (a && b) {
        if (ar1[a-1] != ar2[0]) {
            forn(i,n) if (i != ar1[a-1] && i != ar2[0]) {
                if (deg[i]&1) posib = false;
            }
            if (deg[ar1[a-1]] % 2 == 0) posib = false;
            if (deg[ar2[0]] % 2 == 0) posib = false;

            cout << (posib ? "Y" : "N") << '\n';
        }
        else {
            forn(i,n) if (deg[i]&1) posib = false;
            cout << (posib && deg[ar1[a-1]] != 0 ? "Y" : "N") << '\n';
        }
        
        return 0;
    }

    if (!a && !b) {
        int imp = 0;
        forn(i,n) if (deg[i]&1) imp++;
        cout << ((imp == 0 || imp == 2) ? "Y" : "N") << '\n';
        return 0;
    }

    int pend = 0;
    forn(i,n) if (deg[i]) pend++;

    if (!pend) return cout << "Y\n", 0;

    if (a) {
        int imp = 0;
        forn(i,n) if(deg[i]&1) imp++;

        bool cond = ((deg[ar1[a-1]] & 1) && imp == 2) || (imp == 0 && deg[ar1[a-1]] != 0);
        cout << (cond ? "Y" : "N") << '\n';
        return 0;
    }

    // if (b)
    int imp = 0;
    forn(i,n) if(deg[i]&1) imp++;

    bool cond = ((deg[ar2[0]] & 1) && imp == 2) || (imp == 0 && deg[ar2[0]] != 0);
    cout << (cond ? "Y" : "N") << '\n';
    

    return 0;
}
