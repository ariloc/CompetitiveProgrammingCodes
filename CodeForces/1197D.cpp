#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const ll INF = 9e18;

int main() {
    FAST_IO;

    ll n,m,k; cin >> n >> m >> k;

    pair<pair<ll,ll>,ll> Q[10]; // per remainder
    Q[0] = {{0,0},-1};
    forsn(i,1,10) Q[i] = {{-INF,-INF},-INF};

    ll s = 0, maxi = 0;
    forn(i,n) {
        ll x; cin >> x; s += x;
        forn(j,10) if (Q[j].snd != -INF) maxi = max(maxi,(s-Q[j].fst.snd)-k*((i-Q[j].snd+m-1)/m));
        Q[(i+1)%m] = max(Q[(i+1)%m],{{-s+k*((i+m)/m),s},i});
    }

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
