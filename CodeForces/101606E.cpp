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

const int MAXN = 5005;
const int INF = 1e9+5;

int dp[MAXN][MAXN]; // con i cuerpos de estudiantes asignados, habiendo probado j edificios
pair<ii,int> rent[MAXN];
ii stud[MAXN]; int rta[MAXN];
ii P[MAXN][MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(j,n) {cin >> stud[j].fst; stud[j].snd = j+1;}
    forn(j,m) {cin >> rent[j].fst.fst; rent[j].snd = j+1;}
    forn(j,m) cin >> rent[j].fst.snd;

    sort(rent,rent+m);
    sort(stud,stud+n);

    forn(j,MAXN) forn(k,MAXN) {dp[j][k] = INF; P[j][k] = {-1,-1};}
    forn(j,MAXN) dp[0][j] = 0;

    forsn(i,1,n+1) forsn(j,1,m+1) {
        if (stud[i-1].fst <= rent[j-1].fst.fst) {
            if (dp[i][j-1] < dp[i][j]) dp[i][j] = dp[i][j-1], P[i][j] = {i,j-1};
            if (dp[i-1][j-1]+rent[j-1].fst.snd < dp[i][j]) dp[i][j] = dp[i-1][j-1]+rent[j-1].fst.snd, P[i][j] = {i-1,j-1};
        }
    }

    if (dp[n][m] == INF) cout << "impossible";
    else {
        for (ii i = {n,m}; i.fst != -1; i = P[i.fst][i.snd]) {
            if (i.fst > 0) rta[stud[i.fst-1].snd] = rent[i.snd-1].snd;
            //cerr << i.fst << ' ' << i.snd << ' ' << rent[i.snd-1].fst.snd << endl;
        }
        forsn(j,1,n+1) cout << rta[j] << ' ';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
