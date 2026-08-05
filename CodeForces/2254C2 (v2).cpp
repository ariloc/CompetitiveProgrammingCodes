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

int const MAXN = 2e5+5;

ll solve(vi &a, vi &b) {
    vi ze1,ze2;
    forn(i,sz(b)) {
        if (b[i] == '1') ze2.pb(i);
        if (a[i] == '1') ze1.pb(i);
    }
    ll r = 0;
    forn(i,sz(ze1)) r += abs(ze2[i]-ze1[i]);
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
