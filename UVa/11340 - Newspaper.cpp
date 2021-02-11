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

const int MAXL = 1e4+5;

char inp[MAXL];
map<char,ll> vals;

int main() {
    FAST_IO;

    //freopen("entrada.txt","r",stdin);
    //freopen("salida.txt","w",stdout);

    int t; cin >> t;
    forn(o,t) {
        vals.clear();

        int k; cin >> k;
        forn(i,k) {
            char c; ll v; cin >> c >> v;
            vals[c] = v;
        }

        string s;
        int m; cin >> m; getline(cin,s);
        ld pay = 0;
        forn(i,m) {
            getline(cin,s);
            forn(j,s.size()) pay += vals[s[j]];
        }

        pay /= 100;

        cout << fixed << setprecision(2) << pay << "$\n";
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
