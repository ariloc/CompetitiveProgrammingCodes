#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 1e5+5;
int const BLOCK = 320;

int pwr[MAXN], nxt[MAXN], nxtblock[MAXN], jmpsblock[MAXN];
int block[MAXN];
bitset<MAXN> changed;
int n,q;

void update (int p, int v) {
    pwr[p] = v;
    nxt[p] = p+pwr[p];

    if (nxt[p] >= n) nxt[p] = nxtblock[p] = -1, jmpsblock[p] = 0;
    else if (block[p] != block[nxt[p]]) nxtblock[p] = nxt[p], jmpsblock[p] = 1;
    else nxtblock[p] = nxtblock[nxt[p]], jmpsblock[p] = jmpsblock[nxt[p]]+1;

    vi inds; inds.pb(p);
    changed[p] = true;
    dforn(i,p) {
        if (block[i] != block[p]) break;
        if (nxt[i] != -1 && changed[nxt[i]]) {
            nxtblock[i] = nxtblock[nxt[i]];
            jmpsblock[i] = jmpsblock[nxt[i]]+1;
            changed[i] = true;
            inds.pb(i);
        }
    }
    for (auto &i : inds) changed[i] = false;
}

ii query (int p) {
    int jmps = 0;
    while (nxtblock[p] != -1)
        jmps += jmpsblock[p], p = nxtblock[p];
    while (nxt[p] != -1)
        jmps++, p = nxt[p];
    return {p,jmps};
}

int main() {
    scanf("%d %d",&n,&q);
    forn(i,n) scanf("%d",&pwr[i]);

    forn(i,n) nxt[i] = nxtblock[i] = -1, block[i] = i/BLOCK;

    dforn(i,n) {
        if (i+pwr[i] < n) {
            nxt[i] = i+pwr[i];
            if (block[i] != block[nxt[i]])
                nxtblock[i] = nxt[i], jmpsblock[i] = 1;
            else nxtblock[i] = nxtblock[nxt[i]], jmpsblock[i] = jmpsblock[nxt[i]]+1;
        }
    }

    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (!typ) {
            int a,b; scanf("%d %d",&a,&b), a--;
            update(a,b);
        }
        else {
            int a; scanf("%d",&a), a--;
            ii aux = query(a);
            printf("%d %d\n",aux.fst+1,aux.snd+1);
        }
    }
 
    return 0;
}
