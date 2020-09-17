
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
typedef unsigned long long ull;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        ull x,y,k; cin >> x >> y >> k;
        ull sticksN = k*y+k;

        ull trades = k+((sticksN-1+x-2)/(x-1));

        /*ull low = 0, high = 1e9*1e9;
        while (high-low>1) {
            ull mid = low + (high-low)/2ULL;
            if ((mid*(x)-mid+1) >= sticksN) high = mid;
            else low = mid;
        }
        trades += ((low*(x)-low+1) >= sticksN ? low : high);*/
        cout << trades << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
