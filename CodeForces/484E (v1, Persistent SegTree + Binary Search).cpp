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

int const MAXN = 1e5+5;
int const INF = 1e9;

struct mon {
    int pr,su,maxi;
    int l,r,n;

    mon(int a, int b, int c, int d, int e, int f) : pr(a), su(b), maxi(c), l(d), r(e), n(f){};
    mon(){l = r = -1; n = 1; pr = su = maxi = 0;}
    mon operator+(const mon &o) const {
        return mon(
            pr == n ? n+o.pr : pr,
            o.su == o.n ? su+o.n : o.su,
            max(max(maxi,o.maxi),su+o.pr),
            -1,
            -1,
            n+o.n
            );
    }
};

mon const DFL = mon();

vector<ii> versions;
vector<mon> bag;

int newNode (int i) {
    bag.pb(i == -1 ? mon() : bag[i]);
    return (int)bag.size() - 1;
}

void add(mon &c, int i, int j) {
    mon auxi = (i == -1 ? DFL : bag[i]) + (j == -1 ? DFL : bag[j]);
    c.pr = auxi.pr;
    c.su = auxi.su;
    c.maxi = auxi.maxi;
    c.n = auxi.n;
}

int update (int i, int p, int tl = 0, int tr = MAXN) {
    i = newNode(i);
    if (tr-tl <= 1) {
        bag[i].pr = bag[i].su = bag[i].maxi = 1; // always set 1
        return i;
    }

    int mid = (tl+tr)/2;
    if (p >= mid) bag[i].r = update(bag[i].r, p, mid, tr);
    else bag[i].l = update(bag[i].l, p, tl, mid);

    add(bag[i],bag[i].l,bag[i].r);

    return i;
}

mon query (int i, int bl, int br, int tl = 0, int tr = MAXN) {
    if (i == -1) return DFL;
    if (tl >= br || tr <= bl) return DFL;
    if (tl >= bl && tr <= br) {
        return bag[i];
    }

    int mid = (tl+tr)/2;
    return query(bag[i].l,bl,br,tl,mid) + query(bag[i].r,bl,br,mid,tr);
}

bool posib (int l, int r, int w, int h) {
    int ver = lower_bound(all(versions),(ii){h,-INF})-versions.begin();
    return ver < (int)versions.size() && query(versions[ver].snd,l,r+1).maxi >= w;
}

int main() {
    FAST_IO;

    int n; cin >> n;

    vector<ii> ord;
    forn(i,n) {
        int x; cin >> x;
        ord.pb({x,i});
    }

    sort(all(ord));

    int cur = -1;
    dforn(i,n) {
        if (i < n-1 && ord[i].fst != ord[i+1].fst) {
            versions.pb({ord[i+1].fst,cur});
        }
        cur = update(cur, ord[i].snd);
    }
    versions.pb({ord[0].fst,cur});
    reverse(all(versions));

    int q; cin >> q;
    forn(i,q) {
        int l,r,w; cin >> l >> r >> w; --l,--r;
        
        int low = 1, high = INF+1;
        while (high-low > 1) {
            int mid = (low+high)/2;
            if (posib(l,r,w,mid)) low = mid;
            else high = mid;
        }

        cout << low << '\n';
    }

    return 0;
}
