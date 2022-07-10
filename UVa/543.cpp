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

const int MAXN = 1e6+5;

bitset<MAXN> done;
vi primes;

int main() {
    FAST_IO;

    for (int i = 4; i < MAXN; i+=2) done[i] = true;
    for (int i = 3; i*i < MAXN; i+=2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j+=i)
                done[j] = true;

    forsn(i,2,MAXN) if (!done[i]) primes.pb(i);

    int x;
    while (cin >> x) {
        if (!x) break;

        int posib = -1;
        for(int i = 0; i*i <= (int)primes.size() and primes[i] < x; i++)
            if (!done[x-primes[i]]) {posib = primes[i]; break;}

        if (posib == -1) cout << "Goldbach's conjecture is wrong.\n";
        else cout << x << " = " << posib << " + " << x-posib << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
