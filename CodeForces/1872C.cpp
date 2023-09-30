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

int const MAXN = 1e7+5;

int spf[MAXN];
bitset<MAXN> done;

void criba() {
    for (int i = 4; i < MAXN; i += 2) done[i] = true, spf[i] = 2;
    for (int i = 3; i < MAXN; i += 2)
        if (!done[i])
            for(int j = i+i; j < MAXN; j += i)
                if (!done[j]) spf[j] = i, done[j] = true;
}

int main() {
    criba();

    int t; scanf("%d",&t);

    forn(_,t) {
        int l,r; scanf("%d %d",&l,&r);
        
        if (r <= 3) {
            printf("-1\n");
            continue;
        }

        if (r-l >= 1 || !(r&1)) {
            if (r&1) --r;
            printf("2 %d\n",r-2);
            continue;
        }

        if (spf[r] <= 1) {
            printf("-1\n"); continue;
        }

        printf("%d %d\n",spf[r],r-spf[r]);
    }
    
    return 0;
}
