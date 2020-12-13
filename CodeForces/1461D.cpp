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

set<ll> sums;

void divide (multiset<int> &x, ll sum) {
    sums.insert(sum);

    int mid = ((*x.rbegin())+(*x.begin()))/2;
    multiset<int> ot; int v; ll sum2 = 0;
    while (!x.empty() && (v = (*x.rbegin())) > mid) {
        ot.insert(v); sum -= v; sum2 += v;
        x.erase(prev(x.end()));
    }
    if (ot.empty() || x.empty()) return;
    divide(x,sum); divide(ot,sum2);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,q; cin >> n >> q;
        multiset<int> num; ll s = 0;
        forn(j,n) {int x; cin >> x; num.insert(x); s += x;}
        divide(num,s);
        forn(j,q) {
            int x; cin >> x;
            cout << (sums.count(x) ? "Yes" : "No") << '\n';
        }
        sums.clear();
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
