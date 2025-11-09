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
int const INF = 2e9;

struct mon {
    mon(){maxi = -INF;}
    mon(int ma) : maxi(ma){}
    int maxi;

    mon operator+(const mon &o) const {
        return mon(max(maxi,o.maxi));
    }
};

vi elem;
int arr[MAXN],arr2[MAXN];
mon ST[2*MAXN];
int le[MAXN];
vi toadd[MAXN];
int rta[MAXN];
int N;

void update(int p, int v) {
    p += N;
    ST[p].maxi = max(ST[p].maxi,v);
    while (p > 1) p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query(int l, int r) {
    mon ret = mon();
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) ret = (ret + ST[l++]);
        if (r&1) ret = (ret + ST[--r]);
    }
    return ret;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i], elem.pb(arr[i]), arr2[i] = arr[i];

    sort(all(elem));
    elem.erase(unique(all(elem)),elem.end());

    forn(i,n) arr[i] = lower_bound(all(elem),arr[i])-elem.begin();
    N = (int)elem.size() + 2;

    auto quer = [&](int i) {
        int ind = lower_bound(all(elem),2*arr2[i]+1)-elem.begin();
        mon q = query(ind,N);
        le[i] = q.maxi;
    };

    forn(i,2*N) ST[i] = mon();
    forn(i,n) {
        quer(i); update(arr[i],i);
    }

    forn(i,2*N) ST[i] = mon();
    dforn(i,n) {
        if (le[i] == -INF) quer(i);
        update(arr[i],i);
    }

    forn(i,n) rta[i] = INF;
    int cur = INF;
    forn(k,3) {
        dforn(i,n) {
            cur++;
            for (auto &j : toadd[i]) {
                int calc = j > i ? j-i : n-i+j;
                cur = min(cur, calc);
            }
            rta[i] = min(rta[i],cur);
            if (le[i] != -INF) toadd[le[i]].pb(i);
        }
    }

    forn(i,n) if (rta[i] == INF) cout << "-1 "; else cout << rta[i] << ' ';

    return 0;

}
