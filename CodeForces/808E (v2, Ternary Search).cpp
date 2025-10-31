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

vi nums[3];
ll pref[3][MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) {
        int w,c; cin >> w >> c;
        nums[w-1].pb(c);
    }

    forn(k,3) sort(all(nums[k])), reverse(all(nums[k]));
    forn(k,3) nums[k].pb(0); // dummy

    forn(k,3) forn(i,nums[k].size()) pref[k][i+1] = pref[k][i] + nums[k][i];

    ll maxi = 0;
    forn(i,nums[2].size()) { // with dummy
        int w3 = i*3;
        if (w3 > m) break;

        auto calc = [&](int j) {
            return pref[1][j]+pref[0][min(m-w3-j*2,(int)nums[0].size())];
        };

        int r = min((m-w3)/2, (int)nums[1].size());
        int lo = -1, hi = r;
        while (hi-lo > 1) {
            int mid = (hi+lo)/2;
            if (calc(mid) < calc(mid+1)) lo = mid;
            else hi = mid;
        }
        maxi = max(maxi,calc(hi)+pref[2][i]);
    }

    cout << maxi << '\n';

    return 0;

}
