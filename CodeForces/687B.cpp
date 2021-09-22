#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
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

const int MAXN = 1e6+10;

bitset<MAXN> done,done2;
int primes[MAXN], sz = 0;
vi factors;

void criba(int N) {
    for (int i = 2; i*i <= N; i++)
        if (!done[i])
            for (int j = i+i; j <= N; j+=i) done[j] = true;
    forsn (i,2,N) if (!done[i]) primes[sz++] = i;
}

void getF (int x) {
    forn (i,sz) {
        if (!x) break;
        int mult = 1;
        while (!(x % primes[i])) {mult *= (ll)primes[i]; x /= primes[i];}
        if (mult != 1) factors.pb(mult);
    }
}

int main() {
    FAST_IO;
    memset(primes,-1,sizeof(primes));

    int n,k; cin >> n >> k;

    criba(MAXN-1);
    getF(k);

    int cnt = 0;
    forn (i,n) {
        int x; cin >> x;
        forn (j,factors.size())
            if (!(x % factors[j])) if (!done2[j]) {done2[j] = true; cnt++;}
    }
    if (cnt == factors.size()) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!