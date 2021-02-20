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

const int MAXN = 105;
const int TOP = 5000;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        int cnt = n*(n-1)/2; // cant partidos

        int maxi = 0;
        forn(i,cnt/n+1) { // suponiendo que c/u gana i partidos
            int rest = cnt-n*i; // me quedan rest partidos
            // me fijo si con rest puedo empatando quedar a un puntaje de tds iguales
            if (!((rest*2)%n)) maxi = i;
        }

        vector<vi> rta(n,vi(n,0));
        vi idx(n,0);
        forn(i,n) {
            forn(j,maxi) {
                int ind = (i+j+1)%n;
                rta[i][ind] = 1;
                rta[ind][i] = -1;
            }
        }
        forn(i,n) {
            forsn(j,i+1,n) cout << rta[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
