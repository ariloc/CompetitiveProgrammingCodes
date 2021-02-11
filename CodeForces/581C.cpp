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
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    auto comp = [](const int &lhs, const int &rhs) {
        return (lhs%10) < (rhs%10); // menor resto --> priority queue va por mayor --> mayor resto es menos falta para el próx múltiplo de 10
    };

    priority_queue<int,vi,decltype(comp)> Q(comp);
    ll s = 0;
    forn(i,n) {
        int x; cin >> x;
        if (x < 100) Q.push(x);
        else s += 10;
    }

    while (!Q.empty() && k) {
        auto e = Q.top(); Q.pop();
        int v = min(k,10-(e%10));
        e += v; k -= v;
        if (e == 100) s += 10;
        else Q.push(e);
    }

    while (!Q.empty()) s += Q.top()/10, Q.pop();

    cout << s;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
