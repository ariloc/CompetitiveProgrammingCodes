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

ii ST[2*MAXST]; int lazy[2*MAXST];
col arr[MAXE];
int N;

void build(int i, int tl, int tr) { // empiezo vacío por lo que el mínimo (0) está siempre
    if (tl+1 == tr) ST[i] = {0,1};
    else {
        int mid = (tl+tr)/2;
        build(2*i,tl,mid);
        build(2*i+1,mid,tr);
        ST[i] = {ST[2*i].fst,ST[2*i].snd+ST[2*i+1].snd};
    }
}

void update(int i, int tl, int tr, int bl, int br, bool stat) {
    if (lazy[i]) { // update lazy que paso
        ST[i].fst += lazy[i];
        if (tr-tl > 1) {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }

    if (bl >= br) return; // LUEGO DESPUÉS DEL UPDATE CORTO

    int mid = (tl+tr)/2;
    if (tl >= bl and tr <= br) { // in range
        int delta = (stat ? -1 : 1);
        // veo qué me conviene adelante, con lazys incl.
        if (tr-tl > 1) {
            int a = ST[2*i].fst+lazy[2*i], b = ST[2*i+1].fst+lazy[2*i+1];
            if (a < b and bl < min(br,mid)) { // elijo el menor
                update(2*i,tl,mid,bl,min(br,mid),stat);
                lazy[2*i+1] += delta; // dejo upd para el otro
                ST[i] = ST[2*i]; return;
            }
            else if (b < a and br > max(bl,mid)) {
                update(2*i+1,mid,tr,max(bl,mid),br,stat);
                lazy[2*i] += delta; // dejo upd para el otro
                ST[i] = ST[2*i+1]; return;
            }
            // salgo a procesar si los dos tienen el mismo mínimo -> ambos les afecta igual el delta
            lazy[2*i] += delta; lazy[2*i+1] += delta; // paso a los de abajo
        }

        ST[i].fst += delta; // todo cambia, incluyendo el mínimo, y no hay colisión
    }
    else {
        update(2*i,tl,mid,bl,min(br,mid),stat); // der
        update(2*i+1,mid,tr,max(bl,mid),br,stat); // izq

        if (tr-tl > 1) // update con nuevos valores
            if (ST[2*i].fst == ST[2*i+1].fst) ST[i] = {ST[2*i].fst,ST[2*i].snd+ST[2*i+1].snd};
            else ST[i] = min(ST[2*i],ST[2*i+1]);
    }
}

int main() {
    int n; scanf("%d",&n);

    forn (i,n) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        x1 += ADD; x2 += ADD; y1 += ADD; y2 += ADD;
        arr[2*i] = {y1,y2-1,x1,0};
        arr[2*i+1] = {y1,y2-1,x2,1};
    }

    sort(arr,arr+n+n);
    build(1,0,MAXC); // valores iniciales
    cerr << ST[1].snd << endl;
    int vSt = ST[1].snd;

    int ind = 0;
    ll rta = 0;
    forn(i,MAXC) {
        while (ind < 2*n and arr[ind].x == i) {
            update(1,0,MAXC,arr[ind].y1,arr[ind].y2+1,arr[ind].del);
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
