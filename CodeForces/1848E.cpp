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

int const MAXN = 1e6+5;
int const MAXF = 3e6+5;

map<int,int> F;
bitset<MAXN> done;
int spf[MAXN], inv[MAXF];

void criba() {
    done[0] = done[1] = true;
    for (int i = 4; i < MAXN; i += 2) done[i] = true, spf[i] = 2;
    for (int i = 3; i*i < MAXN; i += 2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j += i)
                if (!done[j]) done[j] = true, spf[j] = i;
}

int x,q,M;
int rta = 1;
int zero_count = 0;

void add (int v) {
    if (!(v%M)) {zero_count++; return;}
    rta = (rta * (ll)(v%M))%M;
}

void del (int v) {
    if (!(v%M)) {zero_count--; return;}
    rta = (rta * (ll)inv[v%M])%M;
}

int main() {
    criba();

    scanf("%d %d %d",&x,&q,&M);

    inv[1] = 1;
    forsn(i,2,MAXF) inv[i] = M - ((ll)(M/i) * inv[M%i])%M;
    
    int aux = x;
    for (int i = 2; i*i < aux; i++) {
        while (!(aux%i)) F[i]++, aux /= i;
    }
    if (aux > 1) F[aux]++;

    for (auto &i : F) if (i.fst != 2) add(i.snd+1);

    forn(i,q) {
        int xi; scanf("%d",&xi);
        while (spf[xi]) {
            bool change = (spf[xi] != 2);
            int prv = F[spf[xi]]+1;

            F[spf[xi]]++, xi /= spf[xi];

            if (change) {
                del(prv);
                add(prv+1);
            }
        }
        if (xi > 1) {
            int prv = F[xi]+1;
            
            F[xi]++;

            if (xi != 2) {
                del(prv);
                add(prv+1);
            }
        }

        printf("%d\n",zero_count ? 0 : (int)((rta + (ll)M)%M));
    }
   
    return 0;
}
