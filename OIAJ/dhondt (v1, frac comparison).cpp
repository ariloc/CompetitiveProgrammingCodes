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

struct frac {
    int n,d;

    bool operator< (const frac &o) const {
        int nd = lcm(d,o.d);
        int n1 = n * (nd/d), n2 = o.n * (nd/o.d);
        return n1 < n2;
    }
};

vector<int> dhondt(int n, vector<int> &v) {
    vi rta(sz(v),0),divs(sz(v),1);
    int total = accumulate(all(v),0);
    forn(i,n) {
        pair<frac,int> maxi = {{0,1},-1};
        forn(j,sz(v)) {
            if (100*v[j] < 3 * total) continue;
            maxi = max(maxi,{{v[j],divs[j]},j});
        }
        divs[maxi.snd]++;
        rta[maxi.snd]++;
    }
    return rta;
}
