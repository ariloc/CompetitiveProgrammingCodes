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
int const MAXM = 3e5+5;

map<ii,ll> edge;
ll dif[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    
    forn(i,m) {
        int u,v,d; cin >> u >> v >> d; --u, --v;
        
        auto it = edge.find({u,v});
        if (it != edge.end()) (*it).snd += d;
        else edge[{u,v}] = d;
    }

    for (auto &i : edge) {
        dif[i.fst.fst] -= i.snd;
        dif[i.fst.snd] += i.snd;
    }

    vi neg,pos;
    forn(i,n) if (dif[i] < 0) neg.pb(i); else if (dif[i] > 0) pos.pb(i);

    vector<pair<ii,ll>> rta;
    while (!neg.empty()) {
        int x = neg.back(); neg.pop_back();
        while (dif[x] < 0 && !pos.empty()) {
            ll val = min(-dif[x], dif[pos.back()]);
            rta.pb({{x,pos.back()},val});
            dif[x] += val, dif[pos.back()] -= val;
            if (!dif[pos.back()]) pos.pop_back();
        }
    }

    cout << (int)rta.size() << '\n';
    for (auto &i : rta) cout << i.fst.fst+1 << ' ' << i.fst.snd+1 << ' ' << i.snd << '\n';

    return 0;

}
