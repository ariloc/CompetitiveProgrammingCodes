#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;
const ll INF = 1e18+10;

ll arr[MAXN];
set<pair<ll,int> > myArr;

int main() {
    FAST_IO;

    ll n,k,x; cin >> n >> k >> x;

    myArr.clear();

    ll neg = 0;
    forn(i,n) {
        ll e; cin >> e;
        if (e < 0) neg++;
        myArr.insert({e,i});
    }

    while (k) {
        auto it = myArr.lower_bound({0,-INF});

        pair<ll,int> nxt = {-1,-1}, prv = {-1,-1};
        if (it != myArr.begin()) prv = *prev(it);
        if (it != myArr.end()) nxt = *it;

        pair<ll,int> choose;
        if (nxt.snd == -1) choose = prv;
        else if (prv.snd == -1) choose = nxt;
        else if (abs(nxt.fst) < abs(prv.fst)) choose = nxt; else choose = prv;

        //cerr << nxt.fst << ' ' << prv.fst << endl;

        ll val;
        if (!(neg & 1)) {
            if (choose.fst < 0) val = choose.fst+x;
            else val = choose.fst-x;
            if ((val < 0)^(choose.fst < 0)) neg++;
        }
        else if (choose.fst < 0) val = choose.fst-x;
        else val = choose.fst+x;

        //
        //cerr << choose.fst << ' '<< val << ' ' << k << ' ' << choose.snd << endl;

        myArr.insert({val,choose.snd});
        myArr.erase(choose);

        k--;
    }

    for (auto &i : myArr) arr[i.snd] = i.fst;

    forn (i,n) cout << arr[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!