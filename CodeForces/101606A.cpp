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
const int INF = 1e9+5;

int isDay[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    int maxi = 0;
    forn(i,n) {
        int h,l,r; cin >> h >> l >> r;
        maxi = max(maxi,h);
        for (int j = l+1; j < MAXN; j+=h) isDay[j]++;
        for (int j = r; j < MAXN; j+=h) isDay[j]--;
        if (l > r) isDay[0]++; // si empieza ya de día
    }

    // TAd
    forsn(j,1,MAXN) isDay[j] += isDay[j-1];

    maxi *= 1825;
    int mini = INF;
    forn(j,maxi+1) if (!isDay[j]) {mini = j; break;}

    if (mini == INF) cout << "impossible";
    else cout << mini;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
