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

const int MAXN = 2e5+2;

int FT[MAXN], rta[MAXN];
ii ord[MAXN];

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int main() {
    FAST_IO;

    int N; cin >> N;
    forn (i,N) {
        int x; cin >> x;
        ord[i] = {x,i};
    }

    sort(ord,ord+N);

    int prim = ord[0].snd;
    forsn (i,1,N) {
        int ind = ord[i].snd;
        //cerr << ind << ' ' << ord[i].fst << ' ' << prim << endl;
        if (ind > prim) {
            rta[i] = rta[i-1]+(ind-prim-1-(i-1))+getFT(ind+1);
            setFT(prim+1,1); setFT(ind+1,-1);
        } else {
            rta[i] = rta[i-1]+(prim-ind+i-1)+getFT(ind+1);
            setFT(1,-1); setFT(ind+1,1); setFT(prim+1,2);
        }
    }

    forn (i,N) cout << rta[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!