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

const int MAXN = 5005;

ll arr[MAXN],acc[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        ll n; cin >> n;
        forn(i,n) cin >> arr[i], acc[i] = 0;

        ll rta = 0;
        forn(i,n) {
            rta += max(0LL,arr[i]-1-acc[i]); // la cantidad de saltos arr[i]-1, le resto los que ya hice de acumulado
            acc[i] = max(0LL,acc[i]-arr[i]+1); // de acumulado lo que aún me sobraría
            dforsn(j,i+2,min(n,i+arr[i]+1)) acc[j]++;
            acc[i+1] += acc[i];
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!