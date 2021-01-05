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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        ll n; cin >> n;
        ll orig = n;

        map<ll,int> F;
        for (ll j = 2; j*j <= n; j++)
            while (!(n%j)) n /= j, F[j]++;
        if (n > 1) F[n]++;

        ll choose = n, cnt = 1;
        for (auto &j : F) if (j.snd > cnt) choose = j.fst, cnt = j.snd;

        vector<ll> num;
        forn(j,cnt-1) num.pb(choose), orig /= choose;
        num.pb(orig);

        cout << num.size() << '\n';
        for (auto &j : num) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
