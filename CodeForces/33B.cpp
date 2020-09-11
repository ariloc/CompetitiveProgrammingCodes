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

const int MAXA = 26;
const int INF = 1e9+5;

int D[MAXA][MAXA];

int main() {
    FAST_IO;

    forn(i,MAXA) forn(j,MAXA) D[i][j] = INF;
    forn(i,MAXA) D[i][i] = 0;
    string A,B; cin >> A >> B;

    int n; cin >> n;
    forn(i,n) {
        string x,y; int c; cin >> x >> y >> c;
        int a = x[0]-'a', b = y[0]-'a';
        D[a][b] = min(D[a][b],c);
    }

    forn(k,MAXA) forn(i,MAXA) forn(j,MAXA)
        D[i][j] = min(D[i][j],D[i][k]+D[k][j]);

    int cost = 0;
    if (A.size() != B.size()) {cout << -1; return 0;}
    forn(i,A.size()) {
        int myC = INF; char ch;
        if (A[i] != B[i]) {
            forn(j,MAXA) {
                int calc = D[A[i]-'a'][j] + D[B[i]-'a'][j];
                if (calc < myC) {ch = j; myC = calc;}
            }
            if (myC >= INF) {cout << -1; return 0;}
            A[i] = ch+'a';
            cost += myC;
        }
    }

    cout << cost << '\n' << A;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
