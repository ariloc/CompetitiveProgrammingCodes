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

const int MAXN = 1e5+2;

vi primes;
bitset<MAXN> done;

void criba () {
    done[0] = done[1] = true;
    for (int i = 4; i < MAXN; i+=2) done[i] = true;
    for (int i = 3; i*i <= MAXN; i+=2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j+=i)
                done[j] = true;

    forn(i,MAXN) if (!done[i]) primes.pb(i);
}

int main() {
    FAST_IO;
    criba();

    int t; cin >> t;
    forn(i,t) {
        int d; cin >> d;

        int ind1 = lower_bound(all(primes),d+1)-primes.begin();
        ll num1 = primes[ind1];
        int ind2 = lower_bound(all(primes),num1+d)-primes.begin();
        ll num2 = primes[ind2];

        cout << num1 * num2 << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
