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

const int MAXN = 3e5+5;
const int INF = 1e9+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        int maxi = 0, ind = -1, sorr = -1;
        forn(j,n) cin >> arr[j];
        forn(j,n) {
            int tmp = min((!j ? INF : arr[j-1]),(j == n-1 ? INF : arr[j+1]));
            if (maxi < arr[j]) {CHANGE: maxi = arr[j]; ind = j; sorr = tmp;}
            else if (maxi == arr[j] && tmp < sorr) goto CHANGE;
        }
        int l = ind-1, r = ind+1, lvl = arr[ind];
        while (r < n || l >= 0) {
            int a = (l < 0 ? INF : arr[l]);
            int b = (r >= n ? INF : arr[r]);
            if (a < b) {
                if (a >= lvl) break;
                l--;
            }
            else {
                if (b >= lvl) break;
                r++;
            }
            lvl++;
        }
        if (r >= n && l < 0) cout << ind+1 << '\n';
        else cout << "-1\n";
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
