#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fst first
#define snd second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int const MAXN = 1e4+5;
int const MAXM = 1e5+5;
ll const INF = 9e18;

int cnt[MAXN];
vector<ii> quer[MAXN];
vi upd[MAXN], del[MAXN];
bool rta[MAXM];

int main(){
    FAST_IO;

    int n,m,q; cin >> n >> m >> q;

    forn(i,m) {
        int k,a,b; cin >> k >> a >> b;
        --a,--b;
        upd[b].pb(b-a);
        del[b+k].pb(b-a);
    }

    forn(i,q) {
        int x,y; cin >> x >> y; --x, --y;
        if (x > y) swap(x,y);
        if (x == y) {
            rta[i] = true;
            continue;
        }
        quer[y].pb({y-x,i});
    }

    forn(i,n) {
        for (auto &j : upd[i]) cnt[j]++;
        for (auto &j : del[i]) cnt[j]--;

        for (auto &j : quer[i]) rta[j.snd] = cnt[j.fst]%2;
    }

    forn(i,q) cout << (rta[i] ? "SI" : "NO") << '\n';

    return 0;
}
