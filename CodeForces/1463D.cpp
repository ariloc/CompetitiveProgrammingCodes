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

int arr[MAXN];
set<int> num;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        int n; cin >> n;
        forn(j,n) cin >> arr[j];

        int ind = 0;
        forn(j,2*n) if (ind >= n || j+1 != arr[ind]) num.insert(j+1); else ind++;

        int r = n, l = -1;
        dforn(j,n) {
            auto it = num.lower_bound(arr[j]);
            if (it == num.begin()) break;
            r = j; num.erase(prev(it));
        }

        ind = 0;
        forn(j,2*n) if (ind >= n || j+1 != arr[ind]) num.insert(j+1); else ind++;

        forn(j,n) {
            auto it = num.upper_bound(arr[j]);
            if (it == num.end()) break;
            l = j; num.erase(it);
        }
        num.clear();

        cout << max(0,l+2-r) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
