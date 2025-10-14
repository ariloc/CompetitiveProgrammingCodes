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

using namespace std;

int const MAXQ = 2e5+5;
ll const MAXV = 1e13+5;
int const MAXBAG = 1e7+5;

struct mon {
    ll s, half; int n;

    mon operator+ (const mon &o) const {
        if (o.n % 2 == 0)
            return {o.s+s, o.half+half, o.n+n};
        return {o.s+s, o.half+s-half, o.n+n};
    }

    mon& operator+= (const ll &v) {
        if (n % 2 == 0) half += v;
        s += v;
        n++;
        return *this;
    }
    
    mon& operator-= (const ll &v) {
        if (n % 2 == 1) half -= v;
        s -= v;
        n--;
        return *this;
    }
};

struct node {
    mon v;
    int l,r;
};

node const DFL = {{0,0,0},-1,-1};

node bag[MAXBAG];
bool init = false;
int nodes = 1;

// true -> add, false -> remove
int update(int i, ll tl, ll tr, const ll &val, const bool &mode) {
    if (tr-tl < 1) return -1;
    if (i == -1) i = nodes, bag[i] = DFL, nodes++;


    if (tr-tl == 1) {
        if (mode) bag[i].v += val;
        else bag[i].v -= val;
        return i;
    }

    ll mid = (tl+tr)/2LL;
    if (val < mid) {
        int auxi = update(bag[i].l, tl, mid, val, mode);
        bag[i].l = auxi;
    }
    else {
        int auxi = update(bag[i].r, mid, tr, val, mode);
        bag[i].r = auxi;
    }

    if (bag[i].l != -1 && bag[i].r != -1)
        bag[i].v = bag[bag[i].l].v + bag[bag[i].r].v;
    else if (bag[i].l != -1) bag[i].v = bag[bag[i].l].v;
    else if (bag[i].r != -1) bag[i].v = bag[bag[i].r].v;

    return i;
}

long long agregar(long long x) {
    if (!init) {
        init = true;
        bag[0] = DFL;
    }
    update(0, 0, MAXV, x, true);
    return bag[0].v.half;
}

long long sacar(long long x) {
    update(0, 0, MAXV, x, false);
    return bag[0].v.half;
}
