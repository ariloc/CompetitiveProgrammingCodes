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

    int t; cin >> t;
    forn(i,t) {
        int x,y; cin >> x >> y;
        string s; cin >> s;
        ii nd = {0,0};
        forn(j,s.size()) {
            if (s[j] == 'L') nd.fst--;
            else if (s[j] == 'R') nd.fst++;
            else if (s[j] == 'U') nd.snd++;
            else nd.snd--;
        }
        forn(j,s.size()) {
            if (nd.fst > x && s[j] == 'R') nd.fst--;
            if (nd.fst < x && s[j] == 'L') nd.fst++;
            if (nd.snd < y && s[j] == 'D') nd.snd++;
            if (nd.snd > y && s[j] == 'U') nd.snd--;
        }
        if (nd.fst == x && nd.snd == y) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
