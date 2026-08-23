#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)c.size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;
typedef __int128 i128;

int const MAXN = 2e5+5;
ld const EPS = 1e-10;

struct edge {
    int v,w;
};

vector<edge> G[MAXN];
i128 dstsq[MAXN],dst[MAXN];
int cntst[MAXN];
bitset<MAXN> done;
ld ret = 0;
int bas = 1000000;

i128 calcd2(edge i) {
    return dstsq[i.v] + cntst[i.v] * (i128)i.w*i.w + dst[i.v]*2*(i128)i.w;
}

i128 calcd(edge i) {
    return dst[i.v] + i.w * (i128)cntst[i.v];
}

int dfs(int st)  {
    done[st] = true;

    int acc = 1;
    for (auto &i : G[st]) {
        if (!done[i.v]) {
            dfs(i.v);
            acc += cntst[i.v];

            dstsq[st] += calcd2(i);
            dst[st] += calcd(i);
        }
    }

    return cntst[st] = acc;
}

i128 dcur = 0, dsqcur = 0;
int cntcur = 0;
void dfs2(int st) {
    done[st] = true;

    dcur += dst[st], dsqcur += dstsq[st], cntcur += cntst[st];
    for (auto &i : G[st]) {
        if (!done[i.v]) {
            i128 subd = calcd(i);
            i128 subd2 = calcd2(i);

            dcur -= subd, dsqcur -= subd2, cntcur -= cntst[i.v];

            i128 a = cntcur + cntst[i.v];
            i128 b = 2*dcur - 2*dst[i.v] - 2LL*cntst[i.v]*i.w;
            i128 c = dsqcur + dstsq[i.v] + 2*(i128)i.w*dst[i.v] + cntst[i.v]*(ll)i.w*i.w;

            ld vert = min(max((ld)0,-b/(ld)(2*a)),(ld)i.w);

            ld val = 0;
            i128 div = 1;
            int divc = 0;
            while ((val = (a/(ld)div) * vert * vert + (b/(ld)div) * vert + (c/(ld)div))-10 > EPS) {
                div *= (i128)10;
                ++divc;
            }
            if (divc < bas || (divc-bas == 0 && val-ret < EPS)) {
                bas = divc; ret = val;
            }

            
            ll add1 = i.w * (ll)cntcur;
            i128 add2 = cntcur * (ll)i.w*i.w + dcur*2*(i128)i.w;

            dcur += add1, dsqcur += add2;
            dfs2(i.v);
            dcur -= add1, dsqcur -= add2;
            dcur += subd, dsqcur += subd2, cntcur += cntst[i.v];
        }
    }
    dcur -= dst[st], dsqcur -= dstsq[st], cntcur -= cntst[st];
}

int main(){
    FAST_IO;

    int n; cin >> n;
    forn(i,n-1) {
        int a,b,d; cin >> a >> b >> d; --a, --b;
        G[a].pb({b,d}), G[b].pb({a,d});
    }

    dfs(0);
    done.reset();
    dfs2(0);

    cout << fixed << setprecision(5) << ret << ' ';
    cout << setprecision(0) << bas << '\n';
    
    return 0;
}
