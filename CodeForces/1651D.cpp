#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 2e5+5;
const int X[] = {1,0,0,-1};
const int Y[] = {0,-1,1,0};
const int INF = 2e8;

struct pt {
    int x,y;

    bool operator< (const pt &o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};

pair<pt,int> pts[MAXN];
set<pt> pt_set;
map<pt,pt> rta;
pt rta_prt[MAXN];

int dist (pt a, pt b) {
    return abs(a.x-b.x) + abs(a.y-b.y);
}

void checkUpd (int i, int k) {
    pt aux = {pts[i].fst.x + X[k], pts[i].fst.y + Y[k]};
    if (!pt_set.count(aux)) return;
    if (dist(rta[aux],pts[i].fst) < dist(pts[i].fst,rta[pts[i].fst]))
        rta[pts[i].fst] = rta[aux];
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d %d",&pts[i].fst.x,&pts[i].fst.y), pts[i].snd = i;
    forn(i,n) pt_set.insert(pts[i].fst), rta[pts[i].fst] = {-INF,-INF};

    sort(pts,pts+n);

    forn(i,n) forn(k,4) {
        int tX = pts[i].fst.x + X[k], tY = pts[i].fst.y + Y[k];
        pt aux = {tX,tY};
        if (!pt_set.count(aux))
            rta[pts[i].fst] = aux;
    }


    forn(i,n) forn(k,4) checkUpd(i,k);
    dforn(i,n) dforn(k,4) checkUpd(i,k);

    forn(i,n) rta_prt[pts[i].snd] = rta[pts[i].fst];

    forn(i,n) printf("%d %d\n",rta_prt[i].x,rta_prt[i].y);

    return 0;
}