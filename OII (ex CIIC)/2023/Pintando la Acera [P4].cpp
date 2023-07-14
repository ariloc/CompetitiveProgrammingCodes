#include <algorithm>
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

int const MAXN = 305;
int const MAXC = 32;
int const INF = 1e9;

struct region {
    int l,r,c;

    region(){}
    region(int l, int r, int c) : l(l), r(r), c(c){}
};

struct estado {
    int cnt,cut;

    estado() : estado(0,-1){}
    estado(int cnt, int cut) : cnt(cnt), cut(cut) {}
};

int arr[MAXN], acera[MAXN];
vector<region> regions;
estado dp[MAXN][MAXN];

int solve(int l, int r) {
    if (r-l <= 0) return 0;
    if (dp[l][r].cnt) return dp[l][r].cnt;


    estado act = estado(INF,-1);
    forsn(i,l,r) {
        if (regions[l].c != regions[i].c) continue;

        bool skip = (r < (int)regions.size() && i+1 < (int)regions.size() && regions[i+1].c == regions[r].c);
        int cnt = solve(l+1,i) + 1 + solve(i+1+skip,r);
        if (cnt < act.cnt) act = estado(cnt,i);
    }

    dp[l][r] = act;
    return act.cnt;
}

void rebuild(int l, int r, vector<region> &rta) {
    if (r-l <= 0) return;

    int cut = dp[l][r].cut;
    rta.pb(region(regions[l].l, regions[cut].r, regions[l].c));
    rebuild(l+1,cut,rta);
    bool skip = (r < (int)regions.size() && cut+1 < (int)regions.size() && regions[cut+1].c == regions[r].c);
    rebuild(cut+1+skip,r,rta);
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    int prv = arr[0], l = 0;
    forn(i,n+1) {
        if (arr[i] != prv) {
            regions.pb({l,i-1,prv});
            l = i;
        }
        prv = arr[i];
    }

    solve(0,(int)regions.size());

    vector<region> rta;
    rebuild(0,(int)regions.size(),rta);

    printf("%d\n",(int)rta.size());
    for (auto &i : rta)
        printf("%d %d %d\n",i.l+1,i.r+1,i.c);
                         
    return 0;
}
