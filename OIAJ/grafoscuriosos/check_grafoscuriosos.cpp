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

const int MAXN = 205;

char mat[MAXN][MAXN],auxmat[MAXN][MAXN],auxmat2[MAXN][MAXN];
int renum[MAXN];

int main() {
    //freopen("grafoscuriosos02.txt","r",stdin);
    //freopen("output_grafoscuriosos02.txt","w",stdout);
    int n; cin >> n;
    forn(i,n) cin >> renum[i];
    forn(i,n) forn(j,n) cin >> mat[i][j], mat[i][j] -= '0';

    forn(i,n) forn(j,n) if (i != j) auxmat[i][j] = 1^mat[i][j];
    forn(i,n) forn(j,n) auxmat2[renum[i]][renum[j]] = auxmat[i][j];

    cout << endl << endl;

    bool isEq = true;
    forn(i,n) forn(j,n) if (auxmat2[i][j] != mat[i][j]) isEq = false;

    forn(i,n) {forn(j,n) cout << (int)mat[i][j]; cout << endl;}
    cout << endl << endl;
    forn(i,n) {forn(j,n) cout << (int)auxmat2[i][j]; cout << endl;}

    cout << (isEq ? "YUP" : "NOPE");

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
