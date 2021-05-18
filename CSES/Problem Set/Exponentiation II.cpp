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
 
const int MOD = 1e9+7;
 
/*map<ll,int> F;
void factorDo(ll n) {
    F.clear();
    for (ll p = 2; p*p <= n; p++)
        while (!(n % p)) F[p]++, n /= p;
    if (n > 1) F[n]++;
}
 
ll eulerPhi (ll n) {
    factorDo(n);
    for (auto &f : F) n -= n/f.fst;
    return n;
}*/
 
int main() {
    FAST_IO;
 
    int t; cin >> t;
 
    forn (i,t) {
        ll a,b,c; cin >> a >> b >> c;
 
        ll PHI = MOD-1;
 
        ll exp = 1;
        while (c) {
            if (c & 1) {exp *= b; exp %= PHI;}
            b *= b; b %= PHI; c >>= 1;
        }
 
        ll rta = 1;
        while (exp) {
            if (exp & 1) {rta *= a; rta %= MOD;}
            a *= a; a %= MOD; exp >>= 1;
        }
 
        cout << rta << '\n';
    }
 
    return 0;
}