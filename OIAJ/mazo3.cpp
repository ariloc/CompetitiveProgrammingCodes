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

int const MAXN = 2e5+5;
int const MAXST = 1<<(32-__builtin_clz(MAXN));

struct mon {
    int dep, sum;
    mon(){dep = sum = 0;};
    mon(int a, int b):dep(a),sum(b){}

    mon operator+ (const mon &o) const {
        return mon(min(dep,o.dep+sum), sum+o.sum);
    }
};

mon ST[2*MAXST];
int N;

mon query(int i, int bl, int br, int tl = 0, int tr = N) {
    if (tr <= bl || tl >= br) return mon();
    if (bl <= tl && tr <= br) return ST[i];
    int mid = (tl+tr)/2;
    return query(2*i,bl,br,tl,mid) + query(2*i+1,bl,br,mid,tr);
}

vector<int> mazo3(string cartas, vector<int> &L, vector<int> &R) {
    int n = sz(cartas);
    N = 1<<(32-__builtin_clz(n));
    forn(i,N) ST[i+N].sum = ST[i+N].dep = cartas[i] == 'R' ? 1 : -1;
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];
    vi rta;
    forn(i,sz(L)) {
        mon que = query(1,L[i], R[i]+1);
        que.dep = min(0,que.dep);
        rta.pb((-que.dep + 1)/2 + (que.sum-que.dep+1)/2);
    }
    return rta;
}
