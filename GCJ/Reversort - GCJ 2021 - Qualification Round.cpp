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

const int MAXN = 105;
const int INF = 1e9+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(o,t) {
        int n; cin >> n;
        forn (i,n) cin >> arr[i];

        int rta = 0;
        forn(i,n-1) {
            int mini = INF, ind = -1;
            forsn(j,i,n)
                if (arr[j] < mini) mini = arr[j], ind = j;
            rta += ind-i+1;
            reverse(arr+i,arr+ind+1);
        }

        cout << "Case #" << o+1 << ": " << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!