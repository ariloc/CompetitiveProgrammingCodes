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

map<int,int> coord1[2];
map<ii,int> coord2;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x,y; cin >> x >> y;
        coord1[0][x]++;
        coord1[1][y]++;
        coord2[{x,y}]++;
    }

    ll cnt = 0;
    for (auto &i : coord1[0]) cnt += (ll)i.snd*(i.snd-1)/2;
    for (auto &i : coord1[1]) cnt += (ll)i.snd*(i.snd-1)/2;
    for (auto &i : coord2) cnt -= (ll)i.snd*(i.snd-1)/2;

    cout << cnt;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
