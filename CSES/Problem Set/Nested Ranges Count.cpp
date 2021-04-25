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

const int MAXR = 2e5+2;
const int MAXN = 2*MAXR;

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

void fp (int x) {
    if (!x) {putchar_unlocked('0'); return;}
    int i = 9;
    char buf[10];
    while (x) buf[i--] = (x%10)+'0', x /= 10;
    while ((++i) < 10) putchar_unlocked(buf[i]);
}

struct range {
    int l,r,id;
};

int FT[MAXN],st[MAXN];
ii rta[MAXN]; // fst -> contains || snd -> is contained
vi toCompress;
range inp[MAXR];

void update(int &x, vi &vec) {
    x = lower_bound(all(vec),x)-vec.begin()+2; // +2 for FT safety
}

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    int n; fs(n);
    forn(i,n) {
        int l,r; fs(l), fs(r);
        toCompress.pb(l), toCompress.pb(r);
        inp[i] = {l,r,i};
    }

    // compression
    sort(all(toCompress));
    toCompress.erase(unique(all(toCompress)),toCompress.end());
    forn(i,n) update(inp[i].l,toCompress), update(inp[i].r,toCompress);

    // sort by ends
    sort(inp,inp+n,[](const range &lhs, const range &rhs){return lhs.r < rhs.r;});
    // TAd in ranges that start in certain prefix
    forn(i,n) st[inp[i].l]++;
    forsn(i,1,MAXN) st[i] += st[i-1];

    forn(i,n) {
        int l = i, r = i+1; // [a,b) of which end in the same coordinate
        while (r < n && inp[r].r == inp[r-1].r) r++;
        forsn(j,l,r) rta[inp[j].id].snd = st[inp[j].l]-getFT(inp[j].l)-1; // -1 so I don't count myself
        forsn(j,l,r) setFT(inp[j].l,1);
        forsn(j,l,r) rta[inp[j].id].fst = getFT(inp[j].r)-getFT(inp[j].l-1)-1; // again, -1 so I don't count myself
        i = r-1; // salto al siguiente
    }

    forn(j,n) fp(rta[j].fst), putchar_unlocked(' ');
    putchar_unlocked('\n');
    forn(j,n) fp(rta[j].snd), putchar_unlocked(' ');
    putchar_unlocked('\n');

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
