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

int const MAXN = 2e5+5;

int arr[MAXN], ap[MAXN], fuap[MAXN], cnt[MAXN];
vi rtas[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,q; cin >> n >> q;

        forn(i,n) ap[i] = 0, fuap[i] = 0;
        forn(i,q) rtas[i].clear();

        vi nums;
        forn(i,n) cin >> arr[i], nums.pb(arr[i]);

        sort(all(nums));
        nums.erase(unique(all(nums)),nums.end());

        forn(i,n) {
            int x = lower_bound(all(nums),arr[i]) - nums.begin();
            arr[i] = x;
        }

        forn(i,n) fuap[arr[i]]++;

        vector<ii> pars;
        forn(i,n) if (fuap[i]) pars.pb({fuap[i],i});
        sort(all(pars));
        
        int b = sqrt(n);

        vector<pair<ii,int>> quer;
        forn(i,q) {
            int l,r; cin >> l >> r; --l, --r;
            quer.pb({{r,l},i});
        }
        sort(all(quer));

        dforn(i,pars.size()) {
            if (pars[i].fst <= b) break;
            
            int idx = 0, cur = 0;
            for (auto &j : quer) {
                int l = j.fst.snd, r = j.fst.fst;
                int cot = (r-l+1)/3;

                if (cot <= b) continue;

                while (idx <= r) {
                    cur = cur + (arr[idx] == pars[i].snd);
                    cnt[idx] = cur;
                    idx++;
                }

                if (cnt[r] - (l-1 < 0 ? 0 : cnt[l-1]) > cot)
                    rtas[j.snd].pb(pars[i].snd);
            }
            forn(j,n) cnt[j] = 0;
        }

        for (auto &i : quer) {
            int l = i.fst.snd, r = i.fst.fst;
            int cot = (r-l+1)/3;

            if (cot <= b) {
                vi seen;
                forsn(j,l,r+1) {
                    if (!ap[arr[j]]) seen.pb(arr[j]);
                    ap[arr[j]]++;
                }
                for (auto &j : seen) {
                    if (ap[j] > cot) rtas[i.snd].pb(j);
                    ap[j] = 0;
                }
            }
        }
        forn(i,q) {
            sort(all(rtas[i]));
            if (rtas[i].empty()) cout << "-1";
            else for (auto &j : rtas[i]) cout << nums[j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}
