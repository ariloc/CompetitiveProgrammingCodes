#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
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

const int MAXN = 1002;
const int STAT = 3;
const int ROT = 4;

bool model[MAXN][MAXN][STAT];

int main() {
    freopen("copia.in","r",stdin);
    freopen("copia.out","w",stdout);

    int T,N; scanf("%d %d",&T,&N);
    T--;

    forn (i,N) {
        char typ,col; int x,st,nd;
        getchar();
        scanf("%c %d %c %d %d",&typ,&x,&col,&st,&nd);
        x--; st--;

        int pt = (col == 'R' ? 0 : (col == 'Z' ? 1 : 2));
        if (typ == 'C') forsn(j,st,nd) model[j][x][pt] = true; // column is 0, row is 1
        else forsn(j,st,nd) model[x][j][pt] = true;
    }

    int M; scanf("%d",&M);

    int bye[ROT] = {-1,-1,-1,-1};
    forn (i,M) {
        char typ,col; int x,st,nd;
        getchar();
        scanf("%c %d %c %d %d",&typ,&x,&col,&st,&nd);
        x--; st--;

        int pt = (col == 'R' ? 0 : (col == 'Z' ? 1 : 2));
        if (typ == 'C') forsn(j,st,nd) {
            if (bye[0] == -1 and !model[j][x][pt]) bye[0] = i;
            if (bye[1] == -1 and !model[T-x][j][pt]) bye[1] = i;
            if (bye[2] == -1 and !model[T-j][T-x][pt]) bye[2] = i;
            if (bye[3] == -1 and !model[x][T-j][pt]) bye[3] = i;
        }
        else forsn (j,st,nd) {
            if (bye[0] == -1 and !model[x][j][pt]) bye[0] = i;
            if (bye[1] == -1 and !model[T-j][x][pt]) bye[1] = i;
            if (bye[2] == -1 and !model[T-x][T-j][pt]) bye[2] = i;
            if (bye[3] == -1 and !model[j][T-x][pt]) bye[3] = i;
        }
    }

    int maxi = -1;
    forn (i,4) {if (bye[i] == -1) {printf("%d",M); return 0;} maxi = max(bye[i],maxi);}
    printf("%d",maxi);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
