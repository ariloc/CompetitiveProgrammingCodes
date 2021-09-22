#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MOD = 1e9+7;

ll expmod(ll a, ll k) {
    ll r = 1;
    while (k) {
        if (k & 1) {r *= a; r %= MOD;}
        a *= a; a %= MOD; k >>= 1;
    }
    return r;
}

int main() {
    FAST_IO;

    int N; cin >> N;

    cout << ((ll)expmod(3,3*N)-(ll)expmod(7,N) + MOD) % MOD;

    return 0;
}