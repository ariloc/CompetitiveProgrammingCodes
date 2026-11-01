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
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

ordered_multiset multi;
int tim = 0;

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;

    forn(i,n) {
        int x; cin >> x;
        multi.insert({x,tim++});
    }

    forn(i,q) {
        int typ,d; cin >> typ >> d;
        if (typ == 1) {
            int cnt = multi.order_of_key({d+1,-1});
            multi.insert({d+cnt,tim++});
        }
        else if (typ == 2) {
            cout << multi.order_of_key({d+1,-1}) << '\n';
        }
        else {
            if (sz(multi) < d) cout << "invalid\n";
            else cout << (*multi.find_by_order(d-1)).fst << '\n';
        }
    }

    return 0;
}
