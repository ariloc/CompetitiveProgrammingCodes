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

const int MAXN = 502;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,x; cin >> n >> x;
        forn(j,n) cin >> arr[j];

        int cnt = 0; bool posib = false;
        forn(j,n) {
            bool sorted = true;
            forsn(k,1,n) if (arr[k] < arr[k-1]) {sorted = false; break;}
            if (sorted) {posib = true; break;}

            if (arr[j] > x) {swap(arr[j],x); cnt++;}
        }

        cout << (posib ? cnt : -1) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
