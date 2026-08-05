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

int const MAXN = 2e5+5;

int arr[MAXN];
multiset<ll> ot;
int n;
vector<ll> rta;

bool can(int elem) {
    multiset<ll> conj = ot;
    
    rta.clear();
    rta.pb(elem);
    conj.erase(conj.find(elem));

    forn(i,n-1) {
        ll mini = -(rta.back()-1);
        auto it = conj.lower_bound(mini);
        if (it == conj.end()) return false;
        rta.pb(rta.back() + *it);
        conj.erase(it);
    }

    return true;
}

int main() {
    FAST_IO;

    int t;cin  >> t;
    forn(_,t) {
        cin >> n;
        forn(i,n) cin >> arr[i];
    
        ot.clear();
        vi pos;
        forn(i,n) {
            ot.insert(arr[i]);
            if (arr[i] >= 1) pos.pb(arr[i]);
        }

        if (pos.empty()) {
            cout << "-1\n"; continue;
        }

        sort(all(pos));
        pos.erase(unique(all(pos)),pos.end());

        int lo = -1, hi = sz(pos)-1;
        while(hi-lo > 1) {
            int mid = (hi+lo)/2;
            if (can(pos[mid])) hi = mid;
            else lo = mid;
        }

        if (!can(pos[hi])) {
            cout << "-1\n";
            continue;
        }

        forn(i,n) cout << rta[i] << ' ';
        cout << '\n';
    }

    return 0;
}
