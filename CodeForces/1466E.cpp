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

const int MAXN = 5e5+5;
const int MAXB = 61;
const int MOD = 1e9+7;

ll arr[MAXN];
int bitCnt[MAXB];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;

        forn(j,MAXB) bitCnt[j] = 0; // reset

        forn(j,n) {
            cin >> arr[j];
            forn(k,60) if (arr[j] & (1LL<<(ll)k)) bitCnt[k]++; // cuento bits que contribuye c/u
        }

        int rta = 0;
        forn(j,n) {
            int ands = 0, ors = 0;
            forn(k,60) { // suma de pares de AND y OR con arr[j] (basado en bits que contribuye c/u)
                ands =  ( ands + (( (( ((1LL<<(ll)k)%MOD) * ((arr[j]&(1LL<<(ll)k)) > 0))%MOD) * (ll)bitCnt[k] )%MOD) )%MOD;
                ors = ( ors + ( ( ((1LL<<(ll)k)%MOD) * ((arr[j]&(1LL<<(ll)k)) ? n : bitCnt[k]) ) %MOD) )%MOD;
            }
            rta = ( rta + ( ((ll)ands*ors)%MOD ) )%MOD;
        }
        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
;
