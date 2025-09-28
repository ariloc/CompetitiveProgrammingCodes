#include <algorithm>
#include<bits/stdc++.h>
#include <random>

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

int const MAXN = 2e5+5;
int const MAXTRIES = 50;

int arr[MAXN];
vi ap[MAXN];
bitset<MAXN> cand;

int cntap (int x, int l, int r) {
    int der = upper_bound(all(ap[x]), r) - ap[x].begin() - 1;
    int iz = lower_bound(all(ap[x]), l) - ap[x].begin() - 1;
    return max(der-iz,0);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,q; cin >> n >> q;

        forn(i,n) ap[i].clear();
        vi nums;

        forn(i,n) cin >> arr[i], nums.pb(arr[i]);

        sort(all(nums));
        nums.erase(unique(all(nums)), nums.end());

        forn(i,n) {
            int x = lower_bound(all(nums), arr[i]) - nums.begin();
            arr[i] = x;
        }

        forn(i,n) ap[arr[i]].pb(i);

        forn(i,q) {
            int l,r; cin >> l >> r; --l, --r;

            random_device rd;
            mt19937 rng(rd());
            uniform_int_distribution<int> dis(l,r);

            vi cands;
            forn(k,MAXTRIES) {
                int idx = dis(rng);
                if (!cand[arr[idx]]) cand[arr[idx]] = true, cands.pb(arr[idx]);
            }

            int cot = (r-l+1)/3;
            vi rta;
            for (auto &j : cands) {
                cand[j] = false;
                int aps = cntap(j,l,r);
                if (aps > cot)
                    rta.pb(nums[j]);
            }
            sort(all(rta));
            if (rta.empty()) cout << "-1";
            else for (auto &j : rta) cout << j << ' ';
            cout << '\n';
        }
    }

    return 0;
}
