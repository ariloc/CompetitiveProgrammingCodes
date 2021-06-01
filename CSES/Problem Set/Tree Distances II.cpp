#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
 
const int MAXN = 2e5+2;
 
vi G[MAXN];
ll D[MAXN];
int nodes[MAXN];
bitset<MAXN> done, done2;
 
pair<int,ll> maxiMe (int st) {
    done[st] = true;
 
    int cnt = 0; ll val = 0;
    for (auto &i : G[st])
        if (!done[i]) {
            pair<int,ll> prox = maxiMe(i);
            val += 1+prox.fst+prox.snd;
            cnt += prox.fst+1;
        }
 
    D[st] += val;
    nodes[st] += cnt;
 
    return {cnt,val};
}
 
void dfsComplete (int st) {
    done2[st] = true;
 
    for (auto &i : G[st])
        if (!done2[i]) {
            D[i] += (D[st]-(D[i]+nodes[i]))+(nodes[st]-nodes[i]-1);
            nodes[i] += (nodes[st]-nodes[i]);
            dfsComplete(i);
        }
}
 
int main() {
    int N; scanf("%d",&N);
 
    forn (i,N-1) {
        int a,b; scanf("%d %d",&a,&b);
        a--; b--;
        G[a].pb(b); G[b].pb(a);
    }
 
    maxiMe(0);
    dfsComplete(0);
 
    forn (i,N) printf("%lld ",D[i]);
 
    return 0;
}