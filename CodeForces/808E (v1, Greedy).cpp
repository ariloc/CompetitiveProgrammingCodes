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
int const MAXC = 1e9;
ll const MAXT = MAXN*(ll)MAXC;

vi nums[3];
vector<ll> pref[2];
int n,m;

ll calc(int w3) {
    int rest = m-w3;
    if (rest <= 0) return 0;
    ll rta = 0;
    if (!nums[0].empty()) rta = max(rta, nums[0][0] + pref[1][min((rest-1)/2,(int)pref[1].size()-1)]);
    rta = max(rta, pref[0][min(rest/2,(int)pref[0].size()-1)]);
    return rta;
}

int main() {
    FAST_IO;

    cin >> n >> m;
    forn(i,n) {
        int w,c; cin >> w >> c;
        nums[w-1].pb(c);
    }

    forn(k,3) sort(all(nums[k])), reverse(all(nums[k]));

    auto go = [&](int stind) {
        vi auxi = nums[1];
        int i;
        for (i = stind; i < (int)nums[0].size(); i += 2)
            auxi.pb(nums[0][i-1] + nums[0][i]);

        sort(all(auxi));
        reverse(all(auxi));

        pref[stind-1].pb(0);
        ll acc = 0;
        forn(i,auxi.size()) {
            acc += auxi[i];
            pref[stind-1].pb(acc);
        }
    };
    go(1);
    go(2);

    forn(k,3) nums[k].pb(0); // dummy

    ll maxi = 0, acc = 0;
    forn(i,nums[2].size()) { // with dummy
        if (i*3 > m) break;

        maxi = max(maxi,acc+calc(i*3));
        acc += nums[2][i];
    }

    cout << maxi << '\n';

    return 0;

}
