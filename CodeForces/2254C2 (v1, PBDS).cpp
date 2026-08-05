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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int const MAXN = 2e5+5;

ll solve(vi &a, vi &b) {
    vi ze,on;
    forn(i,sz(b)) {
        if (b[i] == '1') on.pb(i);
        else ze.pb(i);
    }
    int ion = 0, ize = 0;
    forn(i,sz(a)) {
        if (a[i] == '0') a[i] = ze[ize++];
        else a[i] = on[ion++];
    }
    ordered_set prev;
    ll r = 0;
    dforn(i,sz(a)) {
        r += prev.order_of_key(a[i]);
        prev.insert(a[i]);
    }
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
 
        string a,b; cin >> a >> b;
    
        int a0 = 0;
        int b0 = 0;
        for (int i = 0; i < sz(a); i += 2) {
            a0 += (a[i] == '0');
            b0 += (b[i] == '0');
        }
        if (a0 != b0) {
            cout << "-1\n"; continue;
        }
 
        a0 = 0, b0 = 0;
        for (int i = 1; i < sz(a); i += 2) {
            a0 += (a[i] == '0');
            b0 += (b[i] == '0');
        }
        if (a0 != b0) {
            cout << "-1\n"; continue;
        }
 
        ll cnt = 0;
        vi oa,ob;
        for (int i = 0; i < sz(a); i += 2) oa.pb(a[i]), ob.pb(b[i]);
        cnt += solve(oa,ob);
        oa.clear(); ob.clear();
        for (int i = 1; i < sz(a); i += 2) oa.pb(a[i]), ob.pb(b[i]);
        cnt += solve(oa,ob);

        cout << cnt << '\n';
    }

    return 0;
}
