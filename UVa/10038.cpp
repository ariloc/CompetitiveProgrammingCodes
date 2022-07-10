#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        int prv = -1;
        set<int> vals; bool ok = true;
        forn(i,n) {
            int x; scanf("%d",&x);
            if (i) {
                int dif = abs(x-prv);
                if (vals.count(dif)) ok = false;
                else if (dif < 1 || dif > n-1) ok = false;
                else vals.insert(dif);
            }
            prv = x;
        }
        printf("%s\n",(ok && (int)vals.size() == n-1 ? "Jolly" : "Not jolly"));
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
