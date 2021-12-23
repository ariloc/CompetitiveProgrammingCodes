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
typedef long double ld;

const int MAXS = 5e5+10;
const int MAXN = 2*MAXS;

struct DS {
    vi p,r;
    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        forn(i,N) p[i] = i;
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

ii segs[MAXS];
int ids[MAXN];
DS UF;

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d %d",&segs[i].fst,&segs[i].snd), segs[i].fst--, segs[i].snd--;
    
    sort(segs,segs+n);
    forn(i,n) ids[segs[i].fst] = ids[segs[i].snd] = i;
    UF.init(2*n);

    set<int> ends;
    int edges = 0;
    forn(i,n) {
        while (!ends.empty() && *ends.begin() < segs[i].fst)
            ends.erase(ends.begin());

        for (auto it = ends.upper_bound(segs[i].fst); it != ends.end() && (*it) < segs[i].snd; it++) {
            UF.join(ids[segs[i].fst], ids[*it]);
            if (edges >= n) return printf("NO"), 0;
            edges++;
        }
        
        ends.insert(segs[i].snd);
    }

    if (edges != n-1) return printf("NO"), 0;
    forsn(i,1,n)
        if (UF.find(ids[segs[i].fst]) != UF.find(ids[segs[i-1].fst]))
            return printf("NO"),0;
    printf("YES");

    
    return 0;
}