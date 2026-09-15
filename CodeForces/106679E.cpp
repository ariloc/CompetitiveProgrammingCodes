#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int const MAXN = 2e5+5;

set<ii> ed1, ed2;
vi g1[MAXN],g[MAXN];
map<ii,int> ids;
int prox_libre = 0;

int getid (ii ar) {
    if (ar.fst > ar.snd) swap(ar.fst,ar.snd);
    auto it = ids.find(ar);
    int curid;
    if (it == ids.end()) {
        ids[ar] = prox_libre;
        curid = prox_libre++;
    }
    else curid = (*it).snd;
    return curid;
}

int nn;
int mt[MAXN],mt2[MAXN],ds[MAXN];

bool bfs() {
    queue<int> q;
    memset(ds,-1,sizeof(ds));
    forsn(i,0,nn)if(mt2[i]<0)ds[i]=0,q.push(i);
    bool r=false;
    while(!q.empty()) {
        int x=q.front();q.pop();
        for(int y:g[x]){
            if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
            else if(mt[y]<0)r=true;
        }
    }
    return r;
}
bool dfs(int x){
    for(int y:g[x])if(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y])){
        mt[y]=x;mt2[x]=y;
        return true;
    }
    ds[x]=1<<30;
    return false;
}
int mm(){
    int r=0;
    memset(mt,-1,sizeof(mt));memset(mt2,-1,sizeof(mt2));
    while(bfs()) {
        forsn(i,0,nn)if(mt2[i]<0)r+=dfs(i);
    }
    return r;
}

int main() {
    FAST_IO;

    int n,m1,m2; cin >> n >> m1 >> m2;

    forn(i,m1) {
        int a,b; cin >> a >> b;
        --a,--b;
        if (a > b) swap(a,b);
        ed1.insert({a,b});
    }
    forn(i,m2) {
        int a,b; cin >> a >> b;
        --a,--b;
        if (a > b) swap(a,b);
        ed2.insert({a,b});
    }

    if (m1 != m2) return cout << "-1\n", 0;

    vector<ii> com;
    for (auto &i : ed2) {
        if (ed1.count(i)) com.pb(i);
    }
    for (auto &i : com) ed1.erase(i), ed2.erase(i);

    for (auto &i : ed1) {
        int myid = getid(i);
        
        forn(j,n) {
            auto add = [&](ii oar) {
                if (oar.fst > oar.snd) swap(oar.fst,oar.snd);
                if (ed2.count(oar)) {
                    int curid = getid(oar);
                    g[myid].pb(curid), g[curid].pb(myid);
                    //cerr << i.fst << ' ' << i.snd << ' ' << oar.fst << ' ' << oar.snd << endl;
                    //cerr << myid << ' ' << curid << endl;
                }
            };
            
            add({i.fst,j});
            add({j,i.snd});
        }
    }

    nn = prox_libre;

    int ot = (int)ed2.size();
    int cnt = mm()/2;
    ot -= cnt;

    cout << cnt + ot*2 << '\n';

    return 0;
}
