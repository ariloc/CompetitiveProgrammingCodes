// https://www.hackerrank.com/contests/simulacro-4-n2-oia-2020/challenges/creando-a-megabot-joacru
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

vector<ll> fact (ll x) {
    vector<ll> r;
    for (ll i = 2; i*i <= x; i++) {
        while (!(x%i)) {x /= i; r.pb(i);}
    }
    if (x > 1) r.pb(x);
    return r;
}

long long megabot(long long A, long long B, long long C)
{
    ll MOD = C;
    ll pot = 1, r = 0;
    while (B) {
        ll tmp = B % 10, tmp2 = 0;
        vector<ll> x = fact(pot);
        //cerr << tmp << ' ' << B << ' ' <<r <<endl;
        tmp2 = (A*tmp)%MOD;
        for (auto &i : x)
            tmp2 = (tmp2*i)%MOD;
        r = (r+tmp2)%MOD;
        B /= 10LL; pot *= 10LL;
    }

    return r;
}

int main()
{
    long long A, B, C;
    cin>>A>>B>>C;
    cout<<megabot(A, B, C)<<endl;
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
