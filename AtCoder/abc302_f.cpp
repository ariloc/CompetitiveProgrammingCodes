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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 4e5+5;

vi G[MAXN];
bitset<MAXN> done;
int n,m;

int bfs (int st) {
    queue<ii> Q;
    Q.push({st,0});
    done[st] = 1;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.fst >= m) e.snd++;
        if (e.fst == m-1) return e.snd;

        for (auto &i : G[e.fst]) {
            if (done[i]) continue;
            done[i] = true;
            Q.push({i,e.snd});
        }
    }
    return 0;
}

int main() {
    FAST_IO;

    cin >> n >> m;
    
    forn(i,n) {
        int a; cin >> a;
        forn(j,a) {
            int x; cin >> x; x--;
            G[m+i].pb(x), G[x].pb(m+i);
        }
    }

    cout << bfs(0)-1;
   
    return 0;
}
