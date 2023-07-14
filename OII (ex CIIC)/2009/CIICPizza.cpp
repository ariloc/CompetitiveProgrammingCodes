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

const int MAXN = 1e5+5;
const int INF = 1e9+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct lazyN {
    int l,r; // creciente b > a || decreciente a > b
};

lazyN ST[2*MAXST];
int N;

void r_update(int i, int tl, int tr, int bl, int br, const int &pos, const int &base, const bool &mode) {
    if (bl >= br) return;

    if (tl == bl and tr == br) {
        if (!mode) ST[i].l = min(ST[i].l,(bl-pos)+base);
        else ST[i].r = min(ST[i].r,(pos-br+1)+base);
        //cerr << bl << ' ' << br << "OK" <<ST[i].l <<' ' << ST[i].r <<  endl;
    }
    else {
        int mid = (tl+tr)/2;
        r_update(2*i,tl,mid,bl,min(br,mid),pos,base,mode);
        r_update(2*i+1,mid,tr,max(bl,mid),br,pos,base,mode);
    }
}

void upd (int x, int y) {
    // y es mi adicional para llegar a la línea de coordenada 0
    r_update(1,0,N, x,N ,x,y,0); // mode 0 es creciente
    r_update(1,0,N, 0,x, x,y,1); // mode 1 es decreciente
}

int query(int i, int tl, int tr, const int &pos) {
    if (tr-tl == 1) {return min(ST[i].l,ST[i].r);}
    else {
        int mid = (tl+tr)/2;
        int meBst = min(ST[i].l+(pos-tl),ST[i].r+(tr-pos-1));
        if (pos >= mid) return min(query(2*i+1,mid,tr,pos),meBst);
        else return min(query(2*i,tl,mid,pos),meBst);
    }
}

int main() {
    int n; scanf("%d",&n);
    N = MAXST;
    forn(i,2*MAXST) ST[i] = {INF,INF};
    forn (i,n) {
        char typ; scanf(" %c ",&typ);
        if (typ == 'I') {
            int x,y; scanf("%d %d",&x,&y);
            upd(x,y);
        }
        else {
            int x; scanf("%d",&x);
            printf("%d\n",query(1,0,N,x));
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
