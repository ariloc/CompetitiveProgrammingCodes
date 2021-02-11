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

const int MAXN = 3e5+5;

set<int> apps[MAXN];
set<ii> notif;
int prox_libre = 1;

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    forn(i,q) {
        int typ,x; cin >> typ >> x;
        if (typ == 1) {
            apps[x].insert(prox_libre);
            notif.insert({prox_libre++,x});
        }
        else if (typ == 2) {
            for (auto &j : apps[x]) notif.erase({j,x});
            apps[x].clear();
        }
        else {
            vector<set<ii>::iterator> toDel;
            for (auto it = notif.begin(); it != notif.end() && (*it).fst <= x; it++)
                toDel.pb(it), apps[(*it).snd].erase((*it).fst);
            for (auto &j : toDel) notif.erase(j);
        }
        cout << notif.size() << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
