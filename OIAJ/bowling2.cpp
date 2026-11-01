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
    int x,y;
};

bool comp(const pt &lhs, const pt &rhs) {
    return lhs.x < rhs.x;
}

int go (vector<pt> &vec, int R) {
    int r = 0, maxi = 0;
    forn(l,sz(vec)) {
        while(r < sz(vec) && vec[r].x - vec[l].x <= 2*R) r++;
        maxi = max(maxi,r-l);
    }
    return maxi;
}

int bowling2(int R, vector<int> &x, vector<int> &y) {
    vector<pt> pts[4];
    int n = sz(x);
    forn(i,n) {
        pt cur = {x[i],y[i]}, otcur = {y[i],x[i]};
        if (cur.x < 0) pts[0].pb(otcur);
        if (cur.x > 0) pts[1].pb(otcur);
        if (cur.y > 0) pts[2].pb(cur);
        if (cur.y < 0) pts[3].pb(cur);
    }
    forn(k,4) sort(all(pts[k]),comp);
    int maxi = 0;
    forn(k,4) maxi = max(maxi,go(pts[k],R));
    return maxi;
}
