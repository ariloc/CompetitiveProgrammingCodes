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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int main() {
    FAST_IO;

    string s; cin >> s;
    reverse(all(s));
    ll n; cin >> n;

    ll rta = 0;
    forn(i,s.size()) {
        if (s[i] == '?') continue;
        ll a = (s[i]-'0');
        rta |= (a<<i);
    }

    if (rta > n) {
        cout << -1;
        return 0;
    }

    dforn(i,s.size()) {
        if (s[i] == '?') {
            if ((rta|(1LL<<i)) <= n) {
                rta |= (1LL<<i);
            }
        }
    }

    cout << rta;

    return 0;
}
