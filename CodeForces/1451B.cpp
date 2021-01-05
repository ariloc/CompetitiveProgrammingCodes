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
        int n,q; cin >> n >> q;
        string s; cin >> s;
        forn(j,q) {
            int l,r; cin >> l >> r; l--; r--;
            bool posib = false;
            vi inds;
            forn(k,n) {
                if (s[k] == s[l]) {
                    l++;
                    if (!inds.empty() && inds.back() != k-1) posib = true;
                    inds.pb(k);
                    if (l > r) break;
                }
            }
            if (!posib) forsn(k,inds.back()+1,n) if (s[k] == s[r]) {posib = true; break;}
            cout << (posib ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
