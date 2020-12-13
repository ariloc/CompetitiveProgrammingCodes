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

const int MAXN = 302;
const int INF = 1e9+5;

char tablero[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) forn(k,n) cin >> tablero[j][k];
        vector<ii> posic[3][2];
        forn(j,n) forn(k,n) if(tablero[j][k] == 'X') posic[(j+k)%3][0].pb({j,k});
        else if (tablero[j][k] == 'O') posic[(j+k)%3][1].pb({j,k});

        int ch1 = 0, ch2 = 0, mini = INF;
        forn(j,3) forn(k,3) {
            if (j == k) continue;
            int s = (int)posic[j][0].size()+(int)posic[k][1].size();
            if (s < mini) {mini = s; ch1 = j; ch2 = k;}
        }

        for (auto &j : posic[ch2][1]) if (tablero[j.fst][j.snd] == 'O') tablero[j.fst][j.snd] = 'X';
        for (auto &j : posic[ch1][0]) if (tablero[j.fst][j.snd] == 'X') tablero[j.fst][j.snd] = 'O';

        forn(j,n) {forn(k,n) cout << tablero[j][k]; cout << '\n';}
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
