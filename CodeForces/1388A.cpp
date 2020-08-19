#include <bits/stdc++.h>

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

const int MINSUM = 30;

/*
const int MAXN = 2e5+5;

bitset<MAXN> notPrime;
vi primes;

void criba (int N) {
    for (int i = 2; i*i <= N; i++)
        if (!notPrime[i])
            for (int j = i+i; j <= N; j+=i)
                notPrime[i] = true;

    forsn (i,2,N+1) if (!notPrime[i]) primes.pb(i);
}*/

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int x; cin >> x;
        if (x <= MINSUM) cout << "NO\n";
        else {
            if (x - MINSUM == 6 or x - MINSUM == 10 or x - MINSUM == 14)
                cout << "YES\n6 10 15" << ' ' << x-(6+10+15) << '\n';
            else cout << "YES\n6 10 14" << ' ' << x-MINSUM << '\n';
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!