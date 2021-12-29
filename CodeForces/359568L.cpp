// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/359568/problem/L
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
typedef unsigned long long ull;


ll binMod (ll a, ll k, ll MOD) {
    ll r = 1; a %= MOD;
    while (k) {
        if (k&1) r = (r*a)%MOD;
        a = (a*a)%MOD; k >>= 1;
    }
    return r;
}

bool is_composite (ll n, ll a, ll d, int s) {
    ll aux = binMod(a,d,n);
    if (aux == 1 || aux == n-1) return false;
    forsn(r,1,s) { 
        aux = (aux*aux)%n;
        if (aux == n-1) return false;
    }
    return true;
}

bool miller_rabin (ll n) { 
    if (n < 2) return false;

    int s = 0;
    ll d = n-1;
    while (!(d&1)) d >>= 1, s++;

    for (int a : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n == a) return true;
        if (is_composite(n,a,d,s))
            return false;
    }
    
    return true;
}

int main() {
    int l,r; scanf("%d %d",&l,&r);

    int cnt = 0;
    forsn(i,l,r+1)
        if (i&1) cnt += miller_rabin(i);

    if (l <= 2 && r >= 2) cnt++;

    printf("%d",cnt);

    return 0;
}