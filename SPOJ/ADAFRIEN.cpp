#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

map<string,ll> cost;

int main() {
    FAST_IO;

    int q,k; cin >> q >> k;
    forn(i,q) {
        string s; int x; cin >> s >> x;
        cost[s] += x;
    }

    vector<ll> costs;
    for (auto &i : cost) costs.pb(i.snd);
    sort(all(costs));

    ll rta = 0;
    reverse(all(costs));
    forn(i,min(k,(int)costs.size())) rta += costs[i];

    cout << rta;
    
    return 0;
}
