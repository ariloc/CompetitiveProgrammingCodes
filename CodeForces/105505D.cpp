#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1005;

string adj[MAXN];
vi G[2*MAXN];
ii ext[MAXN];
bitset<MAXN> inc[2*MAXN];
int cnt[2*MAXN],vot[2*MAXN];
int cur = 0;

vector<int> G2[2*MAXN]; // [0,n)->[0,m)
int n2=0,m2=0;
int mat[2*MAXN];bool vis[2*MAXN];
int match(int x){
    if(vis[x])return 0;
    vis[x]=true;
    for(int y:G2[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
    return 0;
}
vector<pair<int,int> > max_matching(){
    vector<pair<int,int> > r;
    memset(mat,-1,sizeof(mat));
    forn(i,n2)memset(vis,false,sizeof(vis)),match(i);
    forn(i,m2)if(mat[i]>=0)r.pb({mat[i],i});
    return r;
}

bitset<2*MAXN> done;
int col[2*MAXN],as[2*MAXN];

void dfs(int st, int c = 0) {
    done[st] = true;
    col[st] = c;
    if (!c) as[st] = n2++;
    else as[st] = m2++;

    for (auto &i : G[st])
        if (!done[i]) dfs(i,1-c);
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> adj[i];

    ext[0] = {0,1};
    G[0].pb(1), G[1].pb(0);
    inc[0][0] = inc[1][0] = true;
    cnt[0]++, cnt[1]++;
    cur = 2;

    forsn(i,1,n) {
        vi side;
        forn(j,i) if (adj[i][j] == '1') side.pb(j);
        vi todel;
        for (auto &v : side) {
            if (!vot[ext[v].fst]) todel.pb(ext[v].fst);
            if (!vot[ext[v].snd]) todel.pb(ext[v].snd);
            vot[ext[v].fst]++, vot[ext[v].snd]++;
        }
        vi cand;
        for (auto &j : todel) {
            if (vot[j] > 1) cand.pb(j);
            vot[j] = 0; // reset
        }
        if (sz(cand) < 2) {
            vi mis;
            for (auto &v : side) {
                bool ok = false;
                for (auto &k : cand) if (inc[k][v]) ok = true;
                if (!ok) mis.pb(v);
            }
            for (auto &v : mis) {
                int u = ext[v].fst;
                if (cnt[u] > 1) u = ext[v].snd;
                cand.pb(u); // must be on empty one
            }
            while (sz(cand) < 2) cand.pb(cur++);
        }
        G[cand[0]].pb(cand[1]),G[cand[1]].pb(cand[0]);
        inc[cand[0]][i] = inc[cand[1]][i] = true;
        cnt[cand[0]]++, cnt[cand[1]]++;
        ext[i] = {cand[0],cand[1]};
    }

    forn(i,cur) if (!done[i]) dfs(i);
    forn(i,cur) if (!col[i]) for (auto &j : G[i]) G2[as[i]].pb(as[j]);

    cout << sz(max_matching()) << '\n';

    return 0;
}
