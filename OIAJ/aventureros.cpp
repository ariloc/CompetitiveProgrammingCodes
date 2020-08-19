#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e8+2;
const int LOGMAXN = log2(MAXN);

int FT[MAXN];

int getFT (int &a) {
    int v = 0;
    for (int x = a; x; x -= x & -x)
        v += FT[x];
    return v;
}

void setFT (int a, int v) {
    for (int x = a; x < MAXN; x += x & -x)
        FT[x] += v;
}

int FTsrch (int v) {
    int x = 0;
    for (int d = 1<<(LOGMAXN-1); d; d>>=1) {
        if (FT[x|d] < v) {
            x |= d;
            v -= FT[x];
        }
    }
    return x+1;
}

int main() {
    freopen("aventureros.in","r",stdin);
    freopen("aventureros.out","w",stdout);

    int N;
    scanf("%d",&N);

    int rondaSize = N, actPos = 1;
    forn(i,N) setFT(i+1,1);
    forn(i,N-1) {
        ll x;
        scanf("%lld",&x);

        actPos = ((actPos+x)%rondaSize);
        if (!actPos) actPos = rondaSize;

        int pos = FTsrch(actPos);
        printf("%d ",pos);
        setFT(pos,-1);
        rondaSize--;
        if (actPos > rondaSize) actPos = 1;
    }

    printf("\n%d",FTsrch(1));

    return 0;
}
