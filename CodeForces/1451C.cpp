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

const int MAXA = 26;

int appA[MAXA], appB[MAXA];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        forn(j,MAXA) appB[j] = appA[j] = 0;

        int n,k; cin >> n >> k;
        string a,b; cin >> a >> b;
        forn(j,n) appA[a[j]-'a']++, appB[b[j]-'a']++;
        bool posib = true; int cnt = 0;
        forn(j,MAXA) {
            int v = appA[j]-appB[j];
            bool neg = (v < 0);
            v = abs(v);
            if (v%k) {posib = false; break;}
            cnt += (v/k)*(neg ? -1 : 1);
            if (cnt < 0) {posib = false;}
        }
        if (cnt) posib = false;
        cout << (posib ? "Yes" : "No") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
