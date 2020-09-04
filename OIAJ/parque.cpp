#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1010;

struct node {
    int id,x,y;
};

struct edge {
    int a,b; ll dist;

    bool operator< (const edge &o) const{
        return dist < o.dist;
    }
};

ll pitagoras (int &c1, int &c2) {
    return ll(sqrt((ll)c1*c1+(ll)c2*c2))+2;
}

struct DS {
    vi p,r;

    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        forn(i,N) p[i] = i;
    }

    int find (int &x) {return p[x] == x ? x : (p[x] = find(p[x]));}
    bool sameSet (int &a, int &b) {return (find(a) == find(b));}
    void join (int &a, int &b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return;
        if (r[y] < r[x]) p[y] = x;
        else {
            p[x] = y;
            if (r[x] == r[y]) r[y]++;
        }
    }
};

DS MST;
node farol[MAXN];
edge edges[MAXN*MAXN];
int tmpI = 0;
vi rta[MAXN];

int main() {
    //FAST_IO;
    freopen("parque.in","r",stdin);
    freopen("parque.out","w",stdout);

    int N; scanf("%d",&N);
    MST.init(N+2);

    farol[0] = {0,0,0};
    forn (i,N) {
        int n,a,b; scanf("%d %d %d",&n,&a,&b);
        farol[i+1] = {n,a,b};
    }

    forn (i,N+1) forsn (j,i+1,N+1) {
        if (i == j) continue;
        int c1 = abs(farol[i].x-farol[j].x);
        int c2 = abs(farol[i].y-farol[j].y);
        int a = farol[i].id, b = farol[j].id;
        edges[tmpI++] = {a,b,pitagoras(c1,c2)};
    }

    sort(edges,edges+tmpI);

    ll cable = 0;
    forn (i,tmpI) {
        if (!MST.sameSet(edges[i].a,edges[i].b)) {
            MST.join(edges[i].a,edges[i].b);
            rta[edges[i].a].pb(edges[i].b);
            rta[edges[i].b].pb(edges[i].a);
            cable += edges[i].dist;
        }
    }

    printf("%lld\n",cable);
    forsn (i,1,N+1) {
        //sort(all(rta[i]));
        printf("%d ",i);
        for (auto &p : rta[i]) printf("%d ",p);
        puts("");
    }

    return 0;
}
