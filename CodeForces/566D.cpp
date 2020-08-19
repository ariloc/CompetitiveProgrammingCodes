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

const int INF = 1e9+2;
const int MAXN = 2e5+5;

vector<ii> UFRanges(MAXN,{INF,-1});

struct DS {
    int p[MAXN], r[MAXN];
    void init() {
        memset(p,-1,sizeof(p));
        memset(r,-1,sizeof(r));
    }
    int find(int &x) {return (p[x] == -1) ? x : (p[x] = find(p[x]));}
    bool sameTeam (int &a, int &b) {return (find(a) == find(b));}
    void join (int a, int &b) {
        if (sameTeam(a,b)) return;
        int x = find(a);
        int y = find(b);
        if (r[x] > r[y]) p[y] = x;
        else {
            p[x] = y;
            if (r[x] == r[y]) r[y]++;
        }
    }
};

DS UF;

int main() {
    UF.init();

    int n,q; scanf("%d %d",&n,&q);

    int typ,a,b,me;
    forn (i,q) {
        scanf("%d %d %d",&typ,&a,&b);
        if (typ == 1) {
            UF.join(a,b);
        }
        else if (typ == 2) {
            set<int> tryJ;
            forsn (j,a+1,b+1) {
                UF.join(j-1,j);
                me = UF.find(a);
                if (UFRanges[me].snd != -1) j = max(j,UFRanges[me].snd);
                tryJ.insert(me);
            }
            for (auto &o : tryJ) {
                UFRanges[o].fst = min(a,UFRanges[o].fst);
                UFRanges[o].snd = max(b,UFRanges[o].snd);
            }
        }
        else {
            if (UF.sameTeam(a,b)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!