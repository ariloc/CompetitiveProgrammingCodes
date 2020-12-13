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

const int MOD = 1e9+7;
const int MAXN = 1e5+2;

int binExp (int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

int calc[MAXN];

int main() {
    FAST_IO;

    calc[0] = 0;
    forsn(i,1,MAXN) calc[i] = (calc[i-1] + (((ll)i*binExp(10,i-1))%MOD))%MOD;

    string s; cin >> s;
    int r = 0;
    forn(i,s.size())
        r = (((r + ((((s[i]-'0') * (ll)calc[(int)s.size()-i-1])%MOD)%MOD))%MOD) +
             (ll)(((((s[i]-'0') * (ll)binExp(10,(int)s.size()-i-1))%MOD) *
                                  (ll)(((((ll)i*(i+1))%MOD)*(MOD+1)/2)%MOD))%MOD))%MOD;

    cout << r;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
