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

const char BK[2] = {'(',')'};

bool isValid (string &s) {
    int op = 0;
    forn(j,s.size()) {
        if (s[j] == '(') op++;
        else op--;
        if (op < 0) return false;
    }
    if (op != 0) return false;
    return true;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        string s; cin >> s;
        string aux; bool posib = false;
        forn(i,2) forn(j,2) forn(k,2) {
            aux.clear();
            forn(l,s.size()) {
                char toPb;
                if (s[l] == 'A') toPb = BK[i];
                else if (s[l] == 'B') toPb = BK[j];
                else toPb = BK[k];
                aux.pb(toPb);
            }

            if (isValid(aux)) {posib = true; goto OUT;}
        }
        OUT: cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
