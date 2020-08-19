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

const int MAXN = 1e5+2;

struct nodo{
    int v,h;

    bool operator< (const nodo &o) const{
        return o.h > h;
    }
};

vector<nodo> G[MAXN];
bitset<MAXN> done;
int K;
int turno = 1;
ii chosen = {-1,-1};

int dfs(int st) {
    done[st] = true;
    int myTurn = -1;

    for (auto &i : G[st])
        if (!done[i.v])
            dfs(i.v);

    myTurn = turno++;
    if (myTurn == K)
        chosen = {st,1};
    return myTurn;
}

int main() {
    int N;
    scanf("%d",&N);

    forn (i,N-1) {
        int T1,h,T2;
        scanf("%d %d %d",&T1,&h,&T2);
        G[T1].push_back({T2,h});
    }
    scanf("%d",&K);

    forn (i,MAXN) sort(G[i].rbegin(),G[i].rend());

    dfs(1);

    printf("%d %d",chosen.fst,chosen.snd);

    return 0;
}
