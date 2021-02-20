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

vector<pair<ld,int>> rta;

int main() {
    FAST_IO;

    int n,t1,t2,k; cin >> n >> t1 >> t2 >> k;
    forn(i,n) {
        int a,b; cin >> a >> b;
        ld dec = (1-k/(ld)100);
        rta.pb({max(a*t2 + b*t1*dec, b*t2 + a*t1*dec),i+1});
    }
    sort(all(rta),[](const auto &lhs, const auto &rhs){
        if (lhs.fst == rhs.fst) return lhs.snd < rhs.snd;
        return lhs.fst > rhs.fst;});
    for (auto &i : rta) cout << i.snd << ' ' << fixed << setprecision(2) << i.fst << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
