#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) (int)c.size()
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int const MAXN = 3e5+5;
ll const MAXID = 1e13;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);}

int arr[MAXN];
ll ids[MAXN];
set<ll> perm;
ll sums[MAXN];

int cnt;

void count(int l, int r) {
    set<int> seen;
    int maxi = 0;
    while (l != r) {
        if (seen.count(arr[l])) break;
        seen.insert(arr[l]);
        maxi = max(maxi, arr[l]);
        if (l-maxi > 0) {
            ll curhash = sums[l+1] - sums[l-maxi+1];
            if (perm.count(curhash)) cnt++;
        }
        l += (r-l > 0 ? 1 : -1);
    }
}

int main(){
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];

    ll cur = 0;
    forn(i,n) {
        ids[i+1] = rnd(1,MAXID);
        cur += ids[i+1];
        perm.insert(cur);
    }

    forn(i,n) sums[i+1] = sums[i] + ids[arr[i]];

    cnt = 0;
    forn(i,n) {
        if (arr[i] != 1) continue;
        set<int> seen;
        int maxi = 1;
        forsn(j,i,n) {
            if (seen.count(arr[j])) break;
            seen.insert(arr[j]);
            maxi = max(maxi, arr[j]);
            if (j-maxi+1 >= 0) {
                ll curhash = sums[j+1] - sums[j-maxi+1];
                if (perm.count(curhash)) cnt++;
            }
        }
        seen.clear();
        seen.insert(1);
        maxi = 1;
        dforn(j,i) {
            if (seen.count(arr[j])) break;
            seen.insert(arr[j]);
            maxi = max(maxi, arr[j]);
            if (j+maxi <= n) {
                ll curhash = sums[j+maxi] - sums[j];
                if (perm.count(curhash)) cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
