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
typedef unsigned long long ull; // UNSIGNED LONG LONG, PORQUE SI NO AL PARECER SE VA :(
typedef pair<int,int> ii;

const int MAXN = 1e5+2;

ull t1[MAXN], t2[MAXN];

int main() {
    FAST_IO;

    ull n,m; cin >> n >> m;
    ull s1 = 0, s2 = 0;
    forn(i,n) {ull x; cin >> x; s1 += x; t1[i] = x;}
    forn(i,m) {ull x; cin >> x; s2 += x; t2[i] = x;}

    ull mini = min(s2*n,s1*m);

    ull tmp_s1 = s1, tmp_s2 = s2;
    sort(t1,t1+n);
    sort(t2,t2+m);

    /* agarrando los más grandes como fijos, pasos todo el resto del otro a mi.
       los que quedan los paso a SOLO UNO de los que haya fijado, pues
       claramente si paso todos los del otro a C/U, ENTONCES UNA VEZ BASTA.
       (no era tan obvio cuando lo hice :'v) */

    dforn(i,n) {
        tmp_s1 -= t1[i];
        mini = min(mini,s2*(n-i)+tmp_s1);
    }

    dforn(i,m) {
        tmp_s2 -= t2[i];
        mini = min(mini,s1*(m-i)+tmp_s2);
    }

    cout << mini;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
