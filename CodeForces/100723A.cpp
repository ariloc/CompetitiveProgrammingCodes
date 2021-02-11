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

const int TOP = 1e9+5;
const ll INF = 9e18;
const int INF_INT = 2e9+5;

map<string,vector<ii>> comps;

ll calcCost (int mid) {
    ll r = 0;
    for (auto &i : comps) {
        int mini = INF_INT;
        for (auto &j : i.snd)
            if (j.snd >= mid) mini = min(mini,j.fst);
        if (mini == INF_INT) return INF;
        r += mini;
    }
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        comps.clear(); // reset

        int n,b; cin >> n >> b;
        forn(j,n) {
            string typ,name; int pr,qual; cin >> typ >> name >> pr >> qual;
            comps[typ].pb({pr,qual});
        }

        int low = 0, high = TOP;
        while (high-low > 1) {
            int mid = (high+low)/2;
            if (calcCost(mid) <= b) low = mid;
            else high = mid;
        }

        if (calcCost(high) <= b) low = high;

        cout << low << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
