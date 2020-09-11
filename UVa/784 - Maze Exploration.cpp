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

const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};
const int MAXN = 100;

char maze[MAXN][MAXN];

int main() {
    int t; scanf("%d",&t); getchar();
    forn(i,t) {
        int h = 0;
        while(scanf("%[^\n]",maze[h++])) {getchar(); if (maze[h-1][0] == '_') break;}
        queue<ii> Q;
        forn(j,MAXN) forn(k,MAXN) if (maze[j][k] == '*') {Q.push({j,k}); maze[j][k] = '#';}

        while (not Q.empty()) {
            auto e = Q.front(); Q.pop();

            forn(j,4) {
                int tY = e.fst+Y[j], tX = e.snd+X[j];
                if (tY >= MAXN or tX >= MAXN or tY < 0 or tX < 0) continue;
                if (maze[tY][tX] != ' ') continue;
                maze[tY][tX] = '#';
                Q.push({tY,tX});
            }
        }

        forn(j,h) printf("%s\n",maze[j]);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
