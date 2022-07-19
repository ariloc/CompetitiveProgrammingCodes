// Statement: https://codeforces.com/group/gXivUSZQpn/contest/336659/problem/A
// ... based on: https://szkopul.edu.pl/problemset/problem/4CirgBfxbj9tIAS2C7DWCCd7/site/?key=statement
// ... or also see: https://codeforces.com/blog/entry/50970

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

const int MAXN = 5005;
const int MAX_Ai = 50005;
const int INF = 2e9;

struct nodo {
    int v,w;

    bool operator< (const nodo &o) const {
        return w < o.w; // para dijkstra
    }
};

int a[MAXN],n;
int D[MAX_Ai];

void dijkstra (int st) {
    forn(i,MAX_Ai) D[i] = -1;

    set<nodo> Q;
    D[st] = 0;
    Q.insert({st,0});    

    while(!Q.empty()) {
        auto e = (*Q.begin()).v; Q.erase(Q.begin());

        forsn(i,1,n) {
            int tg = (e+a[i])%a[0];
            if (D[tg] == -1 || D[tg] > D[e] + a[i]) {
                D[tg] = D[e] + a[i];
                Q.insert({tg,D[tg]});
            }
        }
    }
}

int main() {+
    scanf("%d",&n);
    forn(i,n) scanf("%d",&a[i]);

    dijkstra(0);
    D[0] = a[0];

    int m; scanf("%d",&m);
    forn(i,m) {
        int x; scanf("%d",&x);

        // si puedo, y pude llegar, y en dicho caso puedo formarlo
        if (!x || ( x >= a[0] && D[x%a[0]] != -1 && D[x%a[0]] <= x )) printf("TAK\n");
        else printf("NIE\n");
    }

    return 0;
}