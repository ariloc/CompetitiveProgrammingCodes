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

const int MAXN = 1005;
const int MAXADD = 10000;
const int MAXL = 20005;

struct segm {
    int a,b,id;

    bool operator< (const segm &o) const{
        return o.b > b;
    }
};

segm arr[MAXN];
vector< pair<int,bool> > pt[MAXL]; // segmento | acción ---> agregar es 1, 0 eliminar
bitset<MAXN> done;

int main() {
    FAST_IO;

    int n; cin >> n;

    forn (i,n) {
        int a,b; cin >> a >> b;
        if (a > b) swap(a,b);
        a += MAXADD; b += MAXADD;
        arr[i] = {a,b,i};

        pt[a].pb({i,1});
        pt[b+1].pb({i,0});
    }
    sort(arr,arr+n);

    set<int> actual;
    int ind = 0;

    vi nails;
    forn(i,MAXL) {
        for (auto &e : pt[i]) {
            if (!e.snd) {if (actual.count(e.fst)) actual.erase(e.fst);}
            else actual.insert(e.fst);
        }

        bool flag = false;
        while (ind < n and arr[ind].b == i) {
            if (!done[arr[ind].id]) flag = true;
            ind++;
        }

        if (flag and (!actual.empty())) {
            for (auto &o : actual) done[o] = true;
            nails.pb(i-MAXADD);
            actual.clear();
        }

        if (ind >= n) break;
    }

    cout << nails.size() << '\n';
    for (auto &i : nails) cout << i << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!