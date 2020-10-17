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

const int MAXN = 8;
const int MX = 64;

char grid[MAXN+1][MAXN+1];
ll mks[MX];

void init() {
    forn(i,MX) {
        // marco inválidos
        ll mk = (1LL<<i); int st;
        for(int j = i%8; j < MX; j+=8) mk |= (1LL<<j); // en columna
        for(int j = int(i/8)*8, top = int(i/8)*8+8; j < top; j++) mk |= (1LL<<j); // en fila

        st = i-(9*min(i%8,i/9));
        for(int j = st; j < MX && (j == st || (j%8)); j+=9) mk |= (1LL<<j); // diagonal izq-der

        st = i-(7*min(7-(i%8),i/7));
        for(int j = st; j < MX && (j == st || (j%8 != 7)); j+=7) mk |= (1LL<<j); // diagonal der-izq

        mks[i] = mk;
    }
}

int main() {
    init();
    forn(i,MAXN) scanf("%s",grid[i]);
    int rta = 0; ll base = 0;
    forn(i,MAXN) forn(j,MAXN) if (grid[i][j] == '*') base |= (1LL<<(i*8+(j%8)));
    for(ll a = 0; a < MX; a++)
        if (!(base&(1LL<<a)))
            for(ll b = a+1, mk1 = (base|mks[a]); b < MX; b++)
                if (!(mk1&(1LL<<b)))
                    for(ll c = b+1, mk2 = (mk1|mks[b]); c < MX; c++)
                        if (!(mk2&(1LL<<c)))
                            for(ll d = c+1, mk3 = (mk2|mks[c]); d < MX; d++)
                                if (!(mk3&(1LL<<d)))
                                    for(ll e = d+1, mk4 = (mk3|mks[d]); e < MX; e++)
                                        if (!(mk4&(1LL<<e)))
                                            for(ll f = e+1, mk5 = (mk4|mks[e]); f < MX; f++)
                                                if (!(mk5&(1LL<<f)))
                                                    for(ll g = f+1, mk6 = (mk5|mks[f]); g < MX; g++)
                                                        if (!(mk6&(1LL<<g)))
                                                            for(ll h = g+1, mk7 = (mk6|mks[g]); h < MX; h++)
                                                                if (!(mk7&(1LL<<h))) rta++;
    printf("%d",rta);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
