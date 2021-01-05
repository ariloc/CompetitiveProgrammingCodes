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
        int a,b; cin >> a >> b;
        string s; cin >> s;
        int cnt = 0; bool place = false;
        ll r = 0;
        forn(j,s.size()) if (s[j] == '1' && (j-1 < 0 || s[j-1] == '0')) r += a;
        forsn(j,1,s.size()-1) {
            if (place) cnt++;
            if (s[j] == '0' && s[j-1] == '1') {
                place = true; cnt = 1;
            }
            if (s[j] == '0' && s[j+1] == '1') {
                place = false;
                if (cnt*b < a && cnt) r = (r-a+cnt*b);
                cnt = 0;
            }
        }
        cout << r << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
