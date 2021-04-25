#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 2e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

void fastscan (ll &x) {
    int c; x = 0;
    c=getchar_unlocked();
    if (c<'0'||c>'9') c=getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

ll ST[2*MAXST];
int len[2*MAXST];
pair<ll,ll> lazy[2*MAXST]; // si hay en el primero, es sumar delta. si hay en el segundo, es establecer a x.
int N;

void build() {
    dforsn(i,1,N) ST[i] = ST[2*i]+ST[2*i+1];
}

void getRangesLen(int i, int tl, int tr) {
    len[i] = tr-tl;

    if (tr-tl <= 1) return;
    int mid = (tl+tr)/2;
    getRangesLen(2*i,tl,mid);
    getRangesLen(2*i+1,mid,tr);
}

void passLazy (int i) {
    bool canPass = ((2*i+1) < (2*MAXST));
    if (lazy[i].snd) {
        ST[i] = len[i]*lazy[i].snd;

        if (canPass) {
            lazy[2*i] = {0,lazy[i].snd};
            lazy[2*i+1] = {0,lazy[i].snd};
        }
    }
    ST[i] += len[i]*lazy[i].fst;
    if (canPass) {
        lazy[2*i].fst += lazy[i].fst;
        lazy[2*i+1].fst += lazy[i].fst;
    }
    lazy[i] = {0,0};
}

void upd(int i, int tl, int tr, int bl, int br, const int v, const bool mode) { // mode == 0 -> incresase, else set
    passLazy(i);
    if (bl >= br) return;
    if (bl == tl && br == tr) {
        if (!mode) lazy[i].fst += v;
        else lazy[i] = {0,v};
        passLazy(i);
    }
    else {
        int mid = (tl+tr)/2;
        upd(2*i,tl,mid,bl,min(br,mid),v,mode);
        upd(2*i+1,mid,tr,max(bl,mid),br,v,mode);
        ST[i] = ST[2*i] + ST[2*i+1];
    }
}

ll get(int i, int tl, int tr, const int L, const int R) {
    if (tr <= L || tl >= R) return 0;
    passLazy(i);
    int mid = (tl+tr)/2;
    if (tr <= R && tl >= L) return ST[i];
    return get(2*i,tl,mid,L,R)+get(2*i+1,mid,tr,L,R);
}

int main() {
    ll n,q; fastscan(n); fastscan(q);
    N = (1<<(32-__builtin_clz(n)));
    forn(i,n) fastscan(ST[i+N]);
    build(); getRangesLen(1,0,N);

    forn(i,q) {
        ll typ,a,b,x; fastscan(typ);  fastscan(a); fastscan(b); a--;
        if (typ == 1 || typ == 2) fastscan(x);
        if (typ == 1) upd(1,0,N,a,b,x,0);
        else if (typ == 2) upd(1,0,N,a,b,x,1);
        else printf("%lld\n",get(1,0,N,a,b));
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
