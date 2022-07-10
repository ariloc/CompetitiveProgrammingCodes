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

const int MAXN = 105;
const int INF = 1e9+5;

int main() {
    //FAST_IO;

    //freopen("salida.out","w",stdout);

    int T; scanf("%d",&T);

    forn (i,T) {
        int N,D; scanf("%d %d",&N,&D);

        pair<int,char> rocks[MAXN];
        vector<bool> mark(MAXN,0);
        rocks[0] = {0,'B'}; rocks[N+1] = {D,'B'};
        forn (j,N) scanf(" %c%*c%d",&rocks[j+1].snd,&rocks[j+1].fst);

        int last = 0,maxi = -1;
        forn (j,N+2) {
            if (rocks[j].snd == 'S') mark[j] = true;
            maxi = max(maxi,rocks[j].fst-rocks[last].fst); last = j;
            if (rocks[j].snd == 'S') if (rocks[j+1].snd != 'B') j++;
        }

        last = N+1;
        dforn (j,N+2) {
            if (!mark[j]) {
                maxi = max(maxi,rocks[last].fst-rocks[j].fst);
                last = j;
            }
        }

        printf("Case %d: %d\n",i+1,maxi);

    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
