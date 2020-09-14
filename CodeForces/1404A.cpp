
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
        int n,k; cin >> n >> k;
        string s; cin >> s;
        bool posib = true;
        forn(j,k) {
            char seen = '?';
            for(int o = j; o < n; o += k) {
                if (seen != '?' and s[o] != seen and s[o] != '?') {posib = false; break;}
                if (seen == '?' and s[o] != '?') seen = s[o];
            }
            int cnt = 0;
            for(int o = j; o < n; o += k) {s[o] = seen; cnt++;}
        }

        int z = 0, o = 0;
        forn(j,k) if (s[j] == '0') z++; else if (s[j] == '1') o++;
        if (o > k/2 or z > k/2) posib = false;

        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
