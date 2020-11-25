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

const int MAXN = 1e5+2;
const int INF = 1e9+5;

ii arr[MAXN];
set<ii> bst;
multiset<int> bests;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) {int x; cin >> x; arr[j] = {x,j+1};}
        sort(arr,arr+n);
        forn(j,n) {bst.insert({j+1,1}); bests.insert(1);}
        bool posib = true;
        forn(j,n) {
            auto me = bst.lower_bound({arr[j].snd,-INF});

            if ((*me).snd != (*bests.rbegin())) {posib = false; break;}

            if (me != prev(bst.end())) {
                auto itR = next(me); // el que me sigue
                auto nxt = (*itR); bst.erase(itR);
                int sum = nxt.snd+(*me).snd;
                bst.insert({nxt.fst,sum});
                bests.insert(sum);
            }
            bests.erase(bests.lower_bound((*me).snd)); bst.erase(me); // ojo multiset
        }
        bst.clear(); bests.clear();
        cout << (posib ? "Yes" : "No") << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
