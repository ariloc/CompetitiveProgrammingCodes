#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

int const MAXN = 3e5+5;
int const MAXST = 1<<(32-__builtin_clz(MAXN));
int const INF = 2e9;

struct mon {
    int cnt,val;
    mon(){cnt=0, val = INF;}
    mon(int a, int b):cnt(a),val(b){};

    mon operator+ (const mon &o) const {
        int compi = val;
        int compd = o.val - cnt;
        return mon(cnt+o.cnt, min(compd,compi));
    }
};

mon ST[2*MAXST];
int N;
int quer[MAXN];
vi pts;

mon query(int i, int bl, int br, int tl = 0, int tr = N) {
    if (tl >= br || tr <= bl) return mon();
    if (tl <= bl && br <= tr) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,bl,br,tl,mid) + query(2*i+1,bl,br,mid,tr);
}

void update (int p, mon v) {
    p += N;
    ST[p] = v;
    while (p > 1) p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

int main() {
    FAST_IO;

    int q; cin >> q;
    forn(i,q) cin >> quer[i], pts.pb(abs(quer[i]));

    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());

    N = (1<<(32-__builtin_clz(q)));

    forn(i,N) ST[i+N] = mon();
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    int cnt = 0;
    forn(i,q) {
        int x = lower_bound(all(pts),abs(quer[i]))-pts.begin();
        if (quer[i] < 0) {
            mon cur = ST[x+N];
            --cur.cnt;
            ++cur.val;
            if (!cur.cnt) cur = mon();
            update(x, cur);
            --cnt;
        }
        else {
            mon cur = ST[x+N];
            if (!cur.cnt) cur.val = quer[i];
            cur.cnt++;
            cur.val--;
            update(x, cur);
            ++cnt;
        }

        mon r = query(1,0,N);
        cout << min(r.val+cnt, cnt) << ' ';
    }

    return 0;
}
