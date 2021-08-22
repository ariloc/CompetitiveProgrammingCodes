// https://www.hackerrank.com/contests/contest-1-1624071633/challenges/entradas/problem
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

const ll INF = 1e13;

ll sumPref (ll x, ll k) {return x * (((k-1) * k) / 2LL);}

bool cond (ll n, ll x, ll k) {
    if ((k*k - k) >= (INF/x)) return false; // prevent overflow
    ll sum = sumPref(x,k);
    ll rest = n - sum;
    return (rest - (x * (k-1))) >= x;
}

int main() {
    FAST_IO;

    ll n,k; cin >> n >> k;

    ll low = 1, high = n+1;

    while (high - low > 1) {
        ll mid = (high+low)/2LL;

        if (cond(n,mid,k)) low = mid;
        else high = mid;
    }

    ll acc = low;
    forn(i,k-1) cout << acc << ' ', acc += low;
    cout << n - sumPref(low,k);

    return 0;
}