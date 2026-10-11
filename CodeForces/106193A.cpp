#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

int const MAXV = 1e6+5;

struct oper {
    bool set;
    int v;
    bool sync;
};

bitset<MAXV> rta,dp,dp2;
vector<oper> lst;
vector<ii> sufs;

int main(){
    FAST_IO;

    int n; cin >> n;

    int lset = -1;
    forn(i,n) {
        char op; int v; string typ;
        cin >> op >> v >> typ;

        oper cur = {op == '=', v, typ == "sync"};
        lst.pb(cur);

        if (cur.set) lset = i;
    }

    if (lset == -1) return cout << "1\n", 0;

    int acc = 0;
    dforsn(i,lset+1,n) {
        acc += lst[i].v;
        if (lst[i].sync) sufs.pb({i,acc});
    }

    reverse(all(sufs));

    dp[0] = true;
    forn(i,lset) {
        if (lst[i].set || lst[i].sync) continue;
        dp |= (dp<<lst[i].v);
    }

    if (lst[lset].sync) {
        int curacc = 0;
        dforsn(i,lset,n) curacc += lst[i].v;
        rta |= (dp<<curacc);
    }

    dp.reset();

    forn(i,lset+1) {
        if (lst[i].sync || !lst[i].set) continue;
        dp[lst[i].v] = true;
    }

    int po = 0;
    forn(i,n) {
        if (po < sz(sufs) && i == sufs[po].fst) {
            rta |= (dp<<sufs[po].snd);
            ++po;
        }
        if (!lst[i].sync && !lst[i].set)
            dp |= (dp<<lst[i].v);
    }
    rta |= dp;

    int cnt = 0;
    forsn(i,1,MAXV) cnt += rta[i];

    cout << cnt << '\n';

    return 0;
}
