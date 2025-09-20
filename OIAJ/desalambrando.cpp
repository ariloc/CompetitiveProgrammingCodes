#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

struct edge {
    int u,v,c;

    bool operator< (const edge &o) const {
        return c < o.c;
    }
};

struct DS {
    vi p,r;
    
    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        forn(i,N) p[i] = i;
    }

    int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}

    bool join(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

vector<edge> edges;
DS UF;

long long desalambrando(int N, std::vector<int> &A, std::vector<int> &B, std::vector<int> &C) {
    UF.init(N);

    forn(i,A.size()) edges.pb({A[i]-1,B[i]-1,C[i]});

    sort(all(edges));
    reverse(all(edges));

    ll cost = 0;
    for (auto &i : edges) cost += i.c;
    for (auto &i : edges) {
        if (UF.join(i.u,i.v))
            cost -= i.c;
    }

    return cost;
}
