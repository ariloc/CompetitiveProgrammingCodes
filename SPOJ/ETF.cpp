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

bitset<MAXN> done;
int spf[MAXN];

void criba() {
    done[1] = true;
    for(int i = 4; i < MAXN; i += 2) done[i] = true, spf[i] = 2;
    for(int i = 3; i*i < MAXN; i += 2)
        if (!done[i])
            for(int j = i+i; j < MAXN; j += i)
                if (!done[j]) spf[j] = i, done[j] = true;
}

int main() {
    criba();

    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);

        map<int,int> F;
        while (spf[n]) F[spf[n]]++, n /= spf[n];
        if (n > 1) F[n]++;

        // phi(a*b) = phi(a) * phi(b) iff gcd(a,b) = 1 (i.e. a,b are coprime)
        // Then we can get the prime factors of any number, so it is:
        // phi(n) = phi(p1^k1 * p2^k2 * ... * pn-1^kn-1 * pn^kn) where p_i^k_i are the prime factors of n.
        // Therefore:
        // phi(n) = phi(p1^k1) * phi(p2^k2) * ... * phi(pn-1^kn-1) * phi(pn^kn)
        // Also note that phi(p^k) = p^k - p^(k-1) = p^(k-1) * (p-1), because for each prime, it is NOT
        // coprime with all the multiples of p. That is, p^k - (p^k)/p = p^(k-1) numbers which ARE NOT
        // coprime with p^k.
        
        int r = 1;
        for (auto &i : F) {
            int x = 1;
            forn(j,i.snd-1) x *= i.fst; // p^(k-1)
            x *= (i.fst-1); // p^(k-1) * (p-1)
            r *= x;
        }

        printf("%d\n",r);
    }
    
    return 0;
}
