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
const int MAXC = MAXN*3;

void fastscan(int &x) {
    int c = 0; x = 0;
    c=getchar_unlocked();
    if (c<'0' || c>'9') c=getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

void fastprint(int x) {
    char num[12];
    sprintf(num,"%d",x);
    for(int i = 0; num[i]; i++) putchar_unlocked(num[i]);
}

struct query {
    char c; int a,b;
};

int arr[MAXN],FT[MAXC];
query input[MAXN];
vi compress;

int getFT (int p) {
    int r = 0;
    for(int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void setFT (int p, int v) {
    for(int i = p; i < MAXC; i += i & -i)
        FT[i] += v;
}

void update (int &x) {
    x = (int)(lower_bound(all(compress),x) - compress.begin()) + 1;
}

void compressNums(int n, int q) {
    sort(all(compress));
    compress.erase(unique(all(compress)),compress.end());
    forn(i,n) {update(arr[i]); setFT(arr[i],1);}
    forn(i,q) {if (input[i].c == '?') update(input[i].a); update(input[i].b);}
}

int main() {
    int n,q; fastscan(n); fastscan(q);

    forn(i,n) {
        int x; fastscan(x); arr[i] = x;
        compress.pb(x);
    }

    forn(i,q) {
        char typ; typ = getchar_unlocked(); getchar_unlocked();
        int a,b; fastscan(a); fastscan(b);
        input[i] = {typ,a,b};

        if (typ == '?') compress.pb(a);
        compress.pb(b);
    }

    compressNums(n,q);

    forn(i,q) {
        auto e = input[i];
        if (e.c == '?')
            printf("%d\n",getFT(e.b)-(!(e.a-1) ? 0 : getFT(e.a-1)));
        else {setFT(arr[e.a-1],-1); arr[e.a-1] = e.b; setFT(e.b,1);}
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
