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

const int MAXN = 2e5+2;

int h[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,k; cin >> n >> k;
        forn(j,n) cin >> h[j];
        pair<ll,ll> range = {h[0]-k+1,h[0]+k-1};
        bool posib = true;
        forsn(j,1,n) {
            pair<ll,ll> meR = {h[j],h[j]+k-1};
            if (j == n-1) meR = {h[j],h[j]};
            pair<ll,ll> allowedR = {max(range.fst,meR.fst),min(range.snd,meR.snd)};
            if (allowedR.snd < allowedR.fst) {posib = false; break;}
            range = {allowedR.fst-k+1,allowedR.snd+k-1};
        }
        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
