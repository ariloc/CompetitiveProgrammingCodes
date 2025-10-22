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

int const MAXN = 16;
int const COT = 1e6;
int const QCOT = 5e6;
ll const KCOT = 1e18;

int arr[MAXN];
vector<ll> ls,rs;
set<ll> Q;

bool oflow (ll a, ll b) {
    return (__int128)a*(__int128)b > KCOT;
}

ll pos(ll x) {
    int l = 0;
    ll cnt = 0;
    dforn(r,rs.size()) {
        while (l < (int)ls.size() && !oflow(ls[l],rs[r]) && ls[l]*rs[r] <= x) l++;
        cnt += l;
    }
    return cnt;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];
    int k; cin >> k;

    if (n == 1) {
        ll cur = 1;
        forn(i,k-1) cur *= arr[0];
        cout << cur << '\n';
        return 0;
    }

    auto run = [](vi &gen, vector<ll> &vec) {
        Q.clear();
        Q.insert(1);
        forn(i,COT) {
            if (Q.empty()) break;
            ll e = *(Q.begin()); Q.erase(Q.begin());
            vec.pb(e);
            forn(j,gen.size())
                if (i+(int)Q.size() <= QCOT && !oflow(e,gen[j]))
                    Q.insert(e*(ll)gen[j]);
        }
    };
    vi gen[2];
    forn(i,n) gen[i&1].pb(arr[i]);
    run(gen[0],ls);
    run(gen[1],rs);

    ll lo = 0, hi = KCOT;
    while (hi-lo > 1) {
        ll mid = (hi+lo)/2LL;
        if (pos(mid) < k) lo = mid;
        else hi = mid;
    }

    cout << hi << '\n';

    return 0;
}
