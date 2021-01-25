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

const int MAXN = 5002;
const int INF = 1e9+5;

struct pc {
    int w,t,id;

    bool operator< (const pc &o) const {
        if (w == o.w) {
            return t < o.t;
        }
        return w > o.w;
    }
};

int main() {
    FAST_IO;

    int n,a,b; cin >> n >> a >> b;

    priority_queue<pc> Q;
    forn(i,n) {
        int t,w; cin >> t >> w; t--;
        Q.push({w,t,i});
    }

    int ac[3] = {0,0,0}; ll tot = 0;
    vector<pc> rta;
    while (!Q.empty() && ac[0]+ac[1]+ac[2] < a+b) {
        auto e = Q.top(); Q.pop();
        if ((!e.t && ac[0] == a) || (e.t == 1 && ac[1] == b)) continue;
        ac[e.t]++; rta.pb(e); tot += e.w;
    }

    cout << rta.size() << ' ' << tot << '\n';
    int cnt[2] = {1,a+1};
    for (auto &i : rta) {
        if (i.t < 2) cout << i.id+1 << ' ' << cnt[i.t]++ << '\n';
        else if (ac[0] < a) cout << i.id+1 << ' ' << cnt[0]++ << '\n', ac[0]++;
        else cout << i.id+1 << ' ' << cnt[1]++ << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
