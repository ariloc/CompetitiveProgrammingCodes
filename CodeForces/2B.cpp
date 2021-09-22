#include <bits/stdc++.h>

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

const int INF = 1e9+2;
const int MAXN = 1005;

int tablero[MAXN][MAXN],mem[MAXN][MAXN][2];
int dp2[MAXN][MAXN],dp5[MAXN][MAXN];
bool P2[MAXN][MAXN], P5[MAXN][MAXN]; // true -> left | false -> up

int main() {
    FAST_IO;

    int N; cin >> N;

    forn(i,N+1) dp2[0][i] = dp2[i][0] = dp5[0][i] = dp5[i][0] = INF;

    ii loc = {-1,-1};
    forsn(i,1,N+1) forsn(j,1,N+1) {
        int x; cin >> x;
        if (!x) {dp2[i][j] = dp5[i][j] = INF; mem[i][j][0] = mem[i][j][1] = INF; loc = {i,j}; continue;}
        while(!(x & 1)) {dp2[i][j]++; x >>= 1;}
        while(!(x % 5)) {dp5[i][j]++; x /= 5;}
        mem[i][j][0] = dp2[i][j]; mem[i][j][1] = dp5[i][j];
    }
/*
        forsn(i,1,N+1) {forsn(j,1,N+1) cout<<dp5[i][j]; cout << endl;}
    cout << endl;
    forsn(i,1,N+1) {forsn(j,1,N+1) cout<<dp2[i][j]; cout << endl;}
    cout << endl;
*/
    dp2[0][1] = dp5[0][1] = 0;
    forsn(i,1,N+1) forsn(j,1,N+1) {
        if (mem[i][j][0] == INF) continue;

        if (dp2[i-1][j] < dp2[i][j-1]) dp2[i][j] += dp2[i-1][j];
        else {dp2[i][j] += dp2[i][j-1]; P2[i][j] = true;}

        if (dp5[i-1][j] < dp5[i][j-1]) dp5[i][j] += dp5[i-1][j];
        else {dp5[i][j] += dp5[i][j-1]; P5[i][j] = true;}
    }

    vector<char> C2,C5;
    int cant[2] = {0,0};
    for (ii x = {N,N}; x.fst > 1 or x.snd > 1; (P2[x.fst][x.snd] ? x.snd-- : x.fst--)) {
        C2.pb((P2[x.fst][x.snd] ? 'R' : 'D'));
        cant[0] += mem[x.fst][x.snd][1];
    }

    for (ii x = {N,N}; x.fst > 1 or x.snd > 1; (P5[x.fst][x.snd] ? x.snd-- : x.fst--)) {
        C5.pb((P5[x.fst][x.snd] ? 'R' : 'D'));
        cant[1] += mem[x.fst][x.snd][0];
    }

    if (loc.fst != -1 and min(min(cant[0],dp2[N][N]),min(cant[1],dp5[N][N])) > 1) { // caso tengo un 0
        cout << "1\n" << string(loc.snd-1,'R') << string(N-1,'D') << string(N-loc.snd,'R');
    }
    else if (min(cant[0],dp2[N][N]) < min(cant[1],dp5[N][N])) {
        cout << min(cant[0],dp2[N][N]) << '\n';
        dforn (i,C2.size()) cout << C2[i];
    }
    else {
        cout << min(cant[1],dp5[N][N]) << '\n';
        dforn (i,C5.size()) cout << C5[i];
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!