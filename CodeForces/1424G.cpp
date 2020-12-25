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

const int MAXN = 1e5+2;

int reg[2*MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int b,d; cin >> b >> d;
        reg[2*i] = b; reg[2*i+1] = -d;
    }

    sort(reg,reg+2*n,[](const int &lhs, const int &rhs){
         if (abs(lhs) == abs(rhs)) return (lhs < 0) > (rhs < 0);
         return abs(lhs) < abs(rhs);});

    int cnt = 0, maxiC = 0, maxiY = -1;
    forn(i,2*n) {
        if (reg[i] > 0) {
            cnt++;
            if (cnt > maxiC) maxiC = cnt, maxiY = reg[i];
        } else cnt--;
    }

    cout << maxiY << ' ' << maxiC;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
