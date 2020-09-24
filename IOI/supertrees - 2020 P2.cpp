#include "supertrees.h"
#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i++)
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 1010;
const int INF = 1e9+5;

bitset<MAXN> done,inAnillo;

struct DS {
    vi p,r;

    void init(int N) {
        p.resize(N,0);
        r.resize(N,0);
        forn(i,N) p[i] = i;
    }

    int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool isSameSet (int a, int b) {return find(a) == find(b);}
    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; if (r[x] == r[y]) r[y]++;
        return true;
    }
};

DS UF;

int construct(std::vector<std::vector<int>> p) {
    int n = p.size(); UF.init(n+5);
    vector<vi> rta(n,vi(n,0));

    bool posib = true;

    forn(i,n) forn(j,n) if (p[i][j] == 1 and UF.join(i,j)) rta[i][j] = rta[j][i] = 1;
    forn(i,n) {
        vi inComp; inComp.pb(i);
        done[UF.find(i)] = true;
        forn(j,n) if (p[i][j] == 2) {
            if(done[UF.find(j)] or UF.isSameSet(i,j)) continue;
            UF.join(i,j); inComp.pb(j);
        }
        if (inComp.size() == 2) posib = false;
        if (inComp.size() == 1) continue;

        forn(j,inComp.size()-1) {
            int a = inComp[j], b = inComp[j+1];
            inAnillo[a] = inAnillo[b] = true;
            rta[a][b] = rta[b][a] = 1;
        }
        rta[inComp[0]][inComp.back()] = rta[inComp.back()][inComp[0]] = 1; // uno anillo
    }


    forn(i,n) forn(j,n) {
        bool sameSet = UF.isSameSet(i,j);
        if (p[i][j] == 3) posib = false;
        if ((p[i][j] > 0) != sameSet) posib = false;
    }

    if (posib) build(rta);

	return posib;
}
