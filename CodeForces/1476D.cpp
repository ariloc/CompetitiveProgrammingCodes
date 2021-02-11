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

const int MAXN = 3e5+2;

int rta[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        string s; cin >> s;

        forn(j,n+1) rta[j] = 0; // reset

        int r = 1;
        forn(l,n) {
            if (l >= r) r = l+1;
            while (r < n && s[r] != s[r-1]) r++;
            //cerr << l << ' ' << r << ' ' << rta[n] << endl;
            forsn(j,l,r+1) if (s[j] == 'R') rta[j] += (r-j);
            dforsn(j,l,r) if (s[j] == 'L') rta[j+1] += (j+1-l);
            l = r-1;
        }

        forn(j,n+1) cout << rta[j]+1 << " \n"[j == n];
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
