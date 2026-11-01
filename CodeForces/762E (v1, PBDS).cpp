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

int const MAXF = 1e4+5;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct st {
    int x,r,f;

    bool operator< (const st &o) const {
        return x < o.x;
    }
};

vector<st> stat;
ordered_set byfreq[MAXF];

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    forn(i,n) {
        int x,r,f; cin >> x >> r >> f;
        stat.pb({x,r,f});
    }

    sort(all(stat));

    priority_queue<ii,vector<ii>,greater<ii>> toDel;
    ll cnt = 0;
    forn(i,sz(stat)) {
        st s = stat[i];
        while (!toDel.empty() && toDel.top().fst < s.x) {
            int j = toDel.top().snd; toDel.pop();
            byfreq[stat[j].f].erase(stat[j].x);
        }
        forsn(j,max(1,s.f-k),min(MAXF,s.f+k+1)) {
            if (byfreq[j].empty()) continue;
            int l = byfreq[j].order_of_key(s.x-s.r);
            cnt += sz(byfreq[j]) - l;
        }
        byfreq[s.f].insert(s.x);
        toDel.push({s.x+s.r,i});
    }

    cout << cnt << '\n';

    return 0;
}
