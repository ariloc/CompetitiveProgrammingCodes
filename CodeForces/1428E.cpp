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

const int MAXN = 1e5+2;
const ll INF = 9e18;

ll difIncrement (ii x) {
    ll myDiv = x.fst/x.snd, rest = x.fst%x.snd;
    return (ll)(x.snd-rest)*myDiv*myDiv + rest*(myDiv+1)*(myDiv+1);
}

auto comp = [](const ii &lhs, const ii &rhs){
    return (difIncrement(lhs)-difIncrement({lhs.fst,lhs.snd+1})) < (difIncrement(rhs)-difIncrement({rhs.fst,rhs.snd+1}));
};
priority_queue<ii,vector<ii>,decltype(comp)> Q(comp);

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) {
        int x; cin >> x;
        Q.push({x,1});
    }

    while (!Q.empty() && (n++) < k) {
        auto e = Q.top(); Q.pop();
        Q.push({e.fst,e.snd+1});
    }

    ll s = 0;
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();
        s += difIncrement(e);
    }

    cout << s;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
