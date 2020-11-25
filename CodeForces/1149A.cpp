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

int main() {
    FAST_IO;

    int n; cin >> n;
    int t1 = 0, t2 = 0;
    forn(i,n) {
        int x; cin >> x;
        if (x == 1) t1++;
        else t2++;
    }
    if (t2) {t2--; cout << "2 ";}
    else {t1--; cout << "1 "; if (t1) {t1--; cout << "1 ";}}
    if (t1) {t1--; cout << "1 ";}
    while (t2-- > 0) cout << "2 ";
    while (t1-- > 0) cout << "1 ";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
