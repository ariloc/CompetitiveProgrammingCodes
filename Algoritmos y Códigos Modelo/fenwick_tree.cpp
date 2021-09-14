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

const int MAXN = 2e5+2;

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

void fp (int x) {
    int i = 9;
    char buf[10];
    while (x) buf[i--] = (x%10)+'0', x /= 10;
    while ((++i) < 10) putchar_unlocked(buf[i]);
}

int FT[MAXN];

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

int invertFT (int v) {
    int x = 0;
    for (int d = (1<<(31-__builtin_clz(MAXN))); d; d >>= 1)
        if ((x|d) < MAXN && FT[x|d] < v) x |= d, v -= FT[x];
    return x+1;
}

int main() {
    int n,k; fs(n), fs(k);
    if (n == 1) return printf("1"), 0;

    forn(j,n) setFT(j+1,1);

    int ind = 1, myN = n+1;
    forn(i,n) {
        ind = (ind+k-1)%(--myN)+1;
        int v = invertFT(ind);
        fp(v); putchar_unlocked(' ');
        setFT(v,-1);
    }

    return 0;
}