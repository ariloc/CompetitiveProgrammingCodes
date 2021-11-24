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
 
const int MAXN = 1e5+2;
 
struct edges {
    int v; ll w; bool halfed = false;
 
    bool operator< (const edges &o) const{
        return w > o.w;
    }
};
 
void fastscan(int &num) {
    int c; num = 0;
    c=getchar();
    if (c == '\n') c=getchar();
    for(; c>='0' && c<='9'; c=getchar())
        num = num*10 + c-'0';
}
 
vector<edges> G[MAXN];
ll D[MAXN][2]; // not claimed or claimed
bool done[MAXN][2];
 
void dijkstra(int st) {
    priority_queue<edges> Q;
    Q.push({st,0,0}); D[st][0] = 0;
 
    while(not Q.empty()) {
        bool orgH = Q.top().halfed;
        auto e = Q.top().v; Q.pop();
 
        if (done[e][orgH]) continue;
        done[e][orgH] = true;
 
        for (auto &i : G[e]) {
            bool meH = orgH | i.halfed;
            if (i.halfed and orgH) continue;
            if (D[i.v][meH] == -1 or D[i.v][meH] > D[e][orgH] + i.w) {
                D[i.v][meH] = D[e][orgH] + i.w;
                Q.push({i.v,D[i.v][meH],meH});
            }
        }
    }
}
 
int main() {
    memset(D,-1,sizeof(D));
    int n,m; fastscan(n); fastscan(m);
 
    forn(i,m) {
        int u,v,w; fastscan(u); fastscan(v); fastscan(w); u--; v--;
        G[u].pb({v,w,false});
        G[u].pb({v,int(w/2),true});
    }
 
    dijkstra(0);
 
    printf("%lld",min(D[n-1][0],D[n-1][1]));
 
    return 0;
}
 
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!