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

ordered_set bycol[2*MAXN];
int arr[MAXN];
vi nums;
vector<ii> quer;

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    forn(i,n) cin >> arr[i], nums.pb(arr[i]);

    forn(i,q) {
        int p,a; cin >> p >> a;
        quer.pb({p,a});
        nums.pb(a);
    }

    sort(all(nums));
    nums.erase(unique(all(nums)),nums.end());

    forn(i,n) arr[i] = lower_bound(all(nums),arr[i])-nums.begin();
    forn(i,q) quer[i].snd = lower_bound(all(nums),quer[i].snd)-nums.begin();

    forn(i,n) bycol[arr[i]].insert(i);

    forn(i,q) {
        auto [p,a] = quer[i];
        bycol[arr[p]].erase(p);
        arr[p] = a;
        bycol[arr[p]].insert(p);
        cout << bycol[arr[p]].order_of_key(p) << '\n';
    }

    return 0;
}
