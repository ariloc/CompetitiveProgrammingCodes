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

const int MAXN = 2005;

const int X[] = {-1,0,1,0};
const int Y[] = {0,1,0,-1};

bool done[MAXN][MAXN];

int main() {
    FAST_IO;

    #ifdef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m; cin >> n >> m;
    int k; cin >> k;

    queue<ii> Q;
    forn(i,k) {
        int x,y; cin >> x >> y; x--, y--;
        done[x][y] = true;
        Q.push({x,y});
    }

    ii last = {-1,-1};
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();
        last = e;

        forn(j,4) {
            int tX = e.fst + X[j], tY = e.snd + Y[j];
            if (done[tX][tY]) continue;
            if (tX < 0 || tY < 0 || tX >= n || tY >= m) continue;
            done[tX][tY] = true;
            Q.push({tX,tY});
        }
    }

    cout << last.fst+1 << ' ' << last.snd+1;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!