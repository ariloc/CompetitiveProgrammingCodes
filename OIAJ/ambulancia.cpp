#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 15001;

struct nodo {
    int v,d;

    bool operator< (const nodo &o) const{
        return o.d < d;
    }
};

vi P1,D1;
vi P2,D2;
vector<nodo> G[MAXN];
int posib[MAXN];
int P,T,S,E;
bitset<MAXN> done;

void dijkstra (vi &P, vi &D, int &st) {
    priority_queue<nodo> Q;
    Q.push({st,0});
    D[st] = 0;

    while (not Q.empty()) {
        auto x = Q.top(); Q.pop();

        for (auto &w : G[x.v]) {
            if (D[w.v] == -1 or D[w.v] > x.d + w.d) {
                P[w.v] = x.v;
                D[w.v] = x.d + w.d;
                Q.push({w.v,D[w.v]});
            }
        }
    }
}

int dp (int &st) {
    int posibles = 0;
    done[st] = true;

    for (auto &i : G[st]) {
        if (D1[i.v] <= D1[st]) continue; // no se acerque a S
        if (D2[i.v] >= D2[st]) continue; // no se aleje a E

        if (i.v == E) {posibles++; continue;}

        if (done[i.v]) {
            if (posib[i.v])
                posibles += posib[i.v];
            continue;
        }

        posibles += dp(i.v);
    }
    posib[st] = posibles;
    return posibles;
}

int main() {
    freopen("ambulancia.in","r",stdin);
    freopen("ambulancia.out","w",stdout);

    scanf("%d %d %d %d",&P,&T,&S,&E);
    S--; E--;

    P1.resize(P+1,-1);
    D1.resize(P+1,-1);
    P2.resize(P+1,-1);
    D2.resize(P+1,-1);

    forn (i,T) {
        int a,b,d;
        scanf("%d %d %d",&a,&b,&d);
        a--; b--;
        G[a].push_back({b,d});
        G[b].push_back({a,d});
    }

    dijkstra(P1,D1,S);
    dijkstra(P2,D2,E);

    cout << dp(S);

    return 0;
}
