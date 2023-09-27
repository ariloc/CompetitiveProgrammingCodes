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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 2e5+5;
int const INF = 2e9;
int const MAXST = (1<<(32-__builtin_clz(MAXN)));

struct mon {
    int v;
    
    mon(){v = -INF;}
    mon(int a) : v(a){}

    mon operator+ (const mon &o) const {
        return {max(v,o.v)};
    }
};

mon ST[2*MAXST];
ii kicks[MAXN];
int N;
vector<ll> pts;

void update (int p, int v) {
    p += N; ST[p].v = max(ST[p].v,v);
    while (p > 1) p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query (int l, int r) {
    mon ret = mon();
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) ret = (ret + ST[l++]);
        if (r&1) ret = (ret + ST[--r]);
}
    return ret;
}

int main() {
    FAST_IO;
    
    int n,v; cin >> n >> v;
    forn(i,n) cin >> kicks[i].fst;
    forn(i,n) cin >> kicks[i].snd;
    kicks[n] = {0,0};
    ++n;

    sort(kicks,kicks+n, [&](const ii &lhs, const ii &rhs) {
        ll a = v*(ll)lhs.fst - lhs.snd;
        ll b = v*(ll)rhs.fst - rhs.snd;
        if (a != b) return a < b;
        return lhs.fst < rhs.fst;
    });

    forn(i,n) pts.pb(v*(ll)kicks[i].fst + kicks[i].snd);
    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());
    
    N = (1<<(32-__builtin_clz(n+5)));
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];
    
    int maxi = 0;
    forn(i,n) {
        ll indaux = v*(ll)kicks[i].fst + kicks[i].snd;
        int ind = lower_bound(all(pts),indaux)-pts.begin();
        
        int r = query(0,ind+1).v;
        if (kicks[i] == (ii){0,0}) r = -1;
        maxi = max(maxi,r+1);
        update(ind,r+1);
    }
    
    cout << maxi << '\n';
    
    return 0;
}
