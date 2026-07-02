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

int const MAXN = 2e6+5;
ll const INF = 9e18;

int h[MAXN];
ll pre[MAXN], dp[MAXN];

void solve (int l, int r, int hei, int k, ll &rta) {
    pre[l] = 0;
    forsn(i,l+1,r+1) pre[i] = pre[i-1] + max(0,hei-h[i]);
    dp[l] = 0;
    forsn(i,l+1,r+1) dp[i] = INF;

    set<ll> vals;
    multiset<ll> vals2;
    int idx = l;
    vals2.insert(0); // dp[l]
    forsn(i,l+1,r+1) {
        while (idx < i && pre[i-1]-pre[idx]-k >= 0) {
            vals.insert(dp[idx]-pre[idx]);
            vals2.erase(vals2.find(dp[idx]));
            idx++;
        }
        if (!vals.empty())
            dp[i] = min(dp[i], (*vals.begin())+pre[i-1]-k + (ll)max(0, hei-h[i]));

        if (!vals2.empty())
            dp[i] = min(dp[i], (*vals2.begin()) + (ll)max(0, hei-h[i]));

        vals2.insert(dp[i]);
    }
        
    rta += dp[r];
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,k; cin >> n >> k;

        vector<ii> vec;
        forn(i,n) cin >> h[i], vec.pb({h[i], i});

        sort(all(vec));

        int highest = vec.back().fst;
        int r = vec.back().snd;
        int l = r;
        vi hi;
        while (!vec.empty() && vec.back().fst == highest) {
            ii cur = vec.back(); vec.pop_back();
            l = cur.snd;
            hi.pb(cur.snd);
        }
        reverse(all(hi));

        ll rta = 0, acc = 0;
        forsn(i,1,hi.size()) {
            solve(hi[i-1],hi[i],highest,k,rta);
        }
        rta += max(0LL,acc-k);

        while (!vec.empty()) {
            int hei = vec.back().fst;
            vi izq,der;
            while (!vec.empty() && vec.back().fst == hei) {
                ii cur = vec.back(); vec.pop_back();
                if (cur.snd < l) izq.pb(cur.snd);
                if (cur.snd > r) der.pb(cur.snd);
            }
            reverse(all(izq)); izq.pb(l);
            der.pb(r); reverse(all(der));
            forn(v,2) {
                vi &curvec = !v ? izq : der;
                forsn(i,1,curvec.size()) {
                    solve(curvec[i-1],curvec[i],hei,k,rta);
                }
            }
            if (!izq.empty()) l = izq[0];
            if (!der.empty()) r = der.back();
        }

        cout << rta << '\n';
    }
   
    return 0;
}
