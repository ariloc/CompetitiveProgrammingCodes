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

const int MAXC = 2e6+5;
const int MAXST = (1<<(32-__builtin_clz(MAXC)));
const int MAXE = 2e5+5;
const int INF = 1e9+5;
const int ADD = 1e6;

struct col { // columna
    int y1,y2,x; // abajo, arriba, x
    bool del; // si elimina, de lo contrario agrega

    bool operator< (const col &o) const{
        return x < o.x;
    }
};

ii operator+ (const ii &a, const ii &b) {
    if (a.fst == b.fst) return {a.fst,a.snd+b.snd};
    return min(a,b);
}

ii ST[2*MAXST]; int lazy[2*MAXST];
col arr[MAXE];

void build() {
    forn(i,MAXST) ST[i+MAXST] = {0,1};
    dforsn(i,1,MAXST) ST[i] = ST[2*i] + ST[2*i+1];
}

void passLazy (int i) {
    ST[i].fst += lazy[i];
    if (2*i+1 < 2*MAXST) {
        lazy[2*i] += lazy[i];
        lazy[2*i+1] += lazy[i];
    }
    lazy[i] = 0;
}

void update(int i, int tl, int tr, int bl, int br, bool op) {
    passLazy(i);
    if (bl >= br) return;
    if (tl == bl && tr == br) {
        int delta = (op ? -1 : 1);
        lazy[i] += delta;
        passLazy(i);
    }
    else {
        int mid = (tl+tr)/2;
        update(2*i,tl,mid,bl,min(br,mid),op);
        update(2*i+1,mid,tr,max(bl,mid),br,op);
        ST[i] = ST[2*i]+ST[2*i+1];
    }
}

int main() {
    int n; scanf("%d",&n);

    forn (i,n) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        x1 += ADD; x2 += ADD; y1 += ADD; y2 += ADD;
        arr[2*i] = {y1,y2,x1,0};
        arr[2*i+1] = {y1,y2,x2,1};
    }

    sort(arr,arr+n+n);
    build(); // valores iniciales
    int vSt = ST[1].snd;

    int ind = 0;
    ll rta = 0;
    forn(i,MAXC) {
        while (ind < 2*n and arr[ind].x == i) {
            update(1,0,MAXST,arr[ind].y1,arr[ind].y2,arr[ind].del);
            ind++;
        }

        ii r = ST[1];
        if (r.fst == 0) rta += vSt-r.snd;
        else rta += vSt;
    }

    printf("%lld",rta);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
