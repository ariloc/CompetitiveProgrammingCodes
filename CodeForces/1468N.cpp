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
        int c1,c2,c3; cin >> c1 >> c2 >> c3;
        int a1,a2,a3,a4,a5; cin >> a1 >> a2 >> a3 >> a4 >> a5;

        c1 -= a1; c2 -= a2; c3 -= a3;
        if (c1 < 0 || c2 < 0 || c3 < 0) {cout << "NO\n"; continue;}

        int aux = min(c1,a4); c1 -= aux; a4 -= aux;
        aux = min(a4,c3); c3 -= aux; a4 -= aux;
        aux = min(c2,a5); c2 -= aux; a5 -= aux;
        aux = min(c3,a5); c3 -= aux; a5 -= aux;

        if (a4 || a5) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
