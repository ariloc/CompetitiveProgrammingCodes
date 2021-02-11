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

const int MAXN = 102;

int dp[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int q,d; cin >> q >> d;

        dp[0] = true;
        forsn(j,1,MAXN) dp[j] = false;
        forn(j,MAXN) {
            forn(k,MAXN) {
                if (j-k < 0) continue;
                int aux = k;
                bool yeah = false;
                while (aux) {
                    if ((aux%10) == d) {yeah = true; break;}
                    aux /= 10;
                }

                if (yeah) dp[j] |= dp[j-k];
            }
        }

        forn(j,q) {
            int x; cin >> x;
            if (x >= d*10) cout << "YES\n";
            else cout << (dp[x] ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
