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

const int MAXN = 1e7+5;
const ll INF = 1e13+5;

bitset<MAXN> done;
int spf[MAXN];
ll pots[MAXN];
vi primes;

void criba() {
    done[0] = done[1] = true; // not primes
    forn(i,MAXN) spf[i] = i;

    for (int i = 4; i < MAXN; i += 2) done[i] = true, spf[i] = 2;
    for (int i = 3; i*i <= MAXN; i += 2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j += i) {
                done[j] = true;
                if (spf[j] == j) spf[j] = i;
            }

    forsn(i,2,MAXN) if (!done[i]) primes.pb(i);
}

bool canDivide (ll n) {
    for (auto &i : primes)
        if (pots[i]) {
            ll acc = 0, aux = 1;
            while ((n/aux) >= i) // si al multiplicar por i, no me paso de n
                aux *= i, acc += n / aux;
            if (acc < pots[i]) return false;
        }
    return true;
}

int main() {
    criba();

    int n; scanf("%d",&n);
    forn(i,n) {int x; scanf("%d",&x); pots[x]++;}
    
    dforn(i,MAXN-1) pots[i] += pots[i+1];
    forsn(i,2,MAXN) 
        if (done[i]) {
            int aux = i;
            while (spf[aux] != aux)
                pots[spf[aux]] += pots[i], aux /= spf[aux];
            if (aux > 1) pots[spf[aux]] += pots[i];
        }

    unsigned long long low = 0, high = INF;
    while (high-low > 1) {
        ll mid = (high+low)/2ULL;
        if (canDivide(mid)) high = mid;
        else low = mid;
    }

    printf("%lld",high);
    
    return 0;
}