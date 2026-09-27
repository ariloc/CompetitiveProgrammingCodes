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

struct pt {
    ll x,y;
    pt(){};
    pt(ll xx, ll yy):x(xx),y(yy){};
    ll operator* (const pt &o) const {return x*o.x + y*o.y;}
};

bool can1(ll v1, ll v2, int R) {
    return (v1-v2)*(v1-v2) <= 4LL*R*R;
}

bool can2(ll v1, ll v2, int R) {
    return 2LL*(v2-v1)*(v2-v1) <= 16LL*R*R;
}

int go(vector<pt> &p, pt dir, int R, bool (*can)(ll,ll,int)) {
    pt perp = {-dir.y,dir.x};
    vector<pair<ll,pt>> proys;
    for (auto &i : p) proys.pb({perp*i,i});
    sort(all(proys),[](const auto &lhs, const auto &rhs){return lhs.fst < rhs.fst;});
    vector<pair<ll,pt>> vecs[4];
    for (auto &i : proys) { // Assuming |x|,|y| > R
        pt cur = i.snd;
        if (cur.y >= 0 && dir.y) vecs[0].pb(i);
        if (cur.y <= 0 && dir.y) vecs[1].pb(i);
        if (cur.x >= 0 && dir.x) vecs[2].pb(i);
        if (cur.x <= 0 && dir.x) vecs[3].pb(i);
    }
    int maxi = 0;
    forn(k,4) {
        int r = 0;
        forn(l,sz(vecs[k])) {
            while (r < sz(vecs[k]) && can(vecs[k][l].fst,vecs[k][r].fst,R))
                r++;
            maxi = max(maxi,r-l);
        }
    }
    return maxi;
}

int bowling3(int R, vector<int> &x, vector<int> &y) {
    vector<pt> pts;
    forn(i,sz(x)) pts.pb({x[i],y[i]});
    int maxi = 0;

    maxi = max(maxi,go(pts,pt(0,1),R,can1));
    maxi = max(maxi,go(pts,pt(1,0),R,can1));
    maxi = max(maxi,go(pts,pt(1,-1),R,can2));
    maxi = max(maxi,go(pts,pt(1,1),R,can2));
    return maxi;
}
