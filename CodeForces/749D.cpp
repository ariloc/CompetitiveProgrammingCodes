#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;

int const MAXN = 2e5+5;

ii bids[MAXN];
vi pper[MAXN];
int n;

int cnt (int mid, vi &out) {
    int r = 0;
    for (auto &i : out) {
        int idx = lower_bound(all(pper[i]),mid)-pper[i].begin();
        r += sz(pper[i])-idx;
    }
    return r;
}

int main() {
    FAST_IO;

    cin >> n;
    forn(i,n) {
        int a,b; cin >> a >> b; --a;
        bids[i] = {a,b};
        pper[a].pb(i);
    }

    int q; cin >> q;
    forn(i,q) {
        int k; cin >> k;
        vi out;
        forn(j,k) {
            int x; cin >> x; --x;
            out.pb(x);
        }

        int lo = -1, hi = n+1;
        while (hi-lo > 1) {
            int mid = (hi+lo)/2;
            if (cnt(mid,out) < n-mid) lo = mid;
            else hi = mid;
        }
        --hi;
        if (hi < 0) {
            cout << "0 0\n";
            continue;
        }

        int per = bids[hi].fst;
        int tim = hi;

        int peridx = lower_bound(all(pper[per]),tim)-pper[per].begin();

        //cerr << per << ' ' << tim << ' ' << pper[per][peridx] << "!!!" << endl; 

        lo = 0; hi = tim;
        out.pb(per);
        while (hi-lo > 1) {
            int mid = (hi+lo)/2;
            if (cnt(mid,out) < n-mid) lo = mid;
            else hi = mid;
        }

        --hi;
        if (!hi) {
            cout << per+1 << ' ' << bids[pper[per][0]].snd << '\n';
            continue;
        }

        int rtaidx = upper_bound(all(pper[per]),hi)-pper[per].begin();

        cout << per+1 << ' ' << bids[pper[per][rtaidx]].snd << '\n';
    }

    return 0;
}
