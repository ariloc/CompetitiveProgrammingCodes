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

const int MAXN = 2e5+5;
const int INF = 1e9;

bitset<MAXN> done;
vi primes;

void criba() {
    for (int i = 4; i < MAXN; i += 2) done[i] = true;
    for (int i = 3; i < MAXN; i += 2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j += i)
                done[j] = true;

    forsn(i,2,MAXN) if (!done[i]) primes.pb(i);
}

int main() {
    FAST_IO;

    criba();
    int n,m; cin >> n >> m;
    
    int tg = *lower_bound(all(primes),m);

    cout << tg << ' ' << tg << '\n';
    forn(i,n-2) cout << i+1 << ' ' << i+2 << " 1\n";
    cout << n-1 << ' ' << n << ' ' << tg - n + 2 << '\n';
    
    m -= (n-1);
    forn(i,n) forsn(j,i+2,n) 
        if (m) cout << i+1 << ' ' << j+1 << ' ' << INF << '\n', m--;
        else goto OUT;

    OUT:

    return 0;
}