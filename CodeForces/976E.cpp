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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;

pll arr[MAXN];

ll gain2 (const pll &x) {
    return x.fst-x.snd;
}

int main() {
    FAST_IO;

    int n,a,b; cin >> n >> a >> b;
    forn(i,n) cin >> arr[i].fst >> arr[i].snd;

    sort(arr,arr+n,[](const pll &lhs, const pll &rhs){
        return gain2(lhs) > gain2(rhs);
    });

    vector<pll> best, worse;
    ll sum_best = 0, sum_worse = 0;

    int auxB = b;
    forn(i,n) {
        if (gain2(arr[i]) > 0 && b) b--, best.pb(arr[i]), sum_best += arr[i].fst;
        else worse.pb(arr[i]), sum_worse += arr[i].snd;
    }

    ll maxi = sum_best + sum_worse;
    if (!auxB) return cout << maxi, 0;
    
    for (auto &i : worse) {
        ll pot = i.fst*(1LL<<a);
        maxi = max(maxi, sum_worse - i.snd + pot + sum_best + 
            (!best.empty() && (int)best.size() >= auxB ? best.back().snd - best.back().fst : 0));
    }

    for (auto &i : best) {
        ll pot = i.fst*(1LL<<a);
        maxi = max(maxi, sum_best - i.fst + pot + sum_worse);
    }

    cout << maxi;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!