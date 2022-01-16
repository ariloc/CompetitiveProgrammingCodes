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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 1e5+10;

int FT[MAXN];

void setFT (int p, int v) {
    p += 2; // OJO! SEGURIDAD FT!!!
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int actL = 0, actR = MAXN;
bool inv = 0;

int main() {
    int n,q; scanf("%d %d",&n,&q);

    actR = n+1;
    forn(i,actR) setFT(i,1); 

    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int p; scanf("%d",&p);

            int len = actR-actL-1;
            int mov = p;

            if (p > (len+1)/2) inv ^= 1, mov = len-p;

            if (!inv) actL += mov;
            else actR -= mov;

            forn(j,mov) {
                int toSet = (!inv ? actL+j+1 : actR-1-j);
                int toGet = (!inv ? actL-j : actR-1+j+1);
                int toGet2 = (!inv ? actL-j-1 : actR-1 + j);
                setFT(toSet, getFT(toGet) - getFT(toGet2));
            }
        }
        else {
            int l,r; scanf("%d %d",&l,&r); l++, r++; // para mantener [a,b) costumbre
            if (!inv) printf("%d\n",getFT(actL+r-1) - getFT(actL+l-1));
            else printf("%d\n", getFT(actR-l) - getFT(actR-r));
        }
    }
    
    return 0;
}