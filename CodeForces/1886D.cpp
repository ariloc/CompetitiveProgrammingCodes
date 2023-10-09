#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 3e5+5;
int const MOD = 998244353;

int inv[MAXN];

int main() {
    FAST_IO;

    inv[1] = 1;
    forsn(i,2,MAXN) inv[i] = MOD - ((MOD/(ll)i)*(ll)inv[MOD%i])%MOD;

    int n,m; cin >> n >> m;
    string s; cin >> s;

    int rta = 1;
    bool nz = 1;
    forsn(i,1,s.size()) {
        if (s[i] == '?') rta = (rta * (ll)i)%MOD;
    }
    if (s[0] == '?') nz = 0;

    cout << rta * nz << '\n';

    forn(i,m) {
        int pos; char c; cin >> pos >> c; --pos;
        if (!pos && c != '?') nz = 1;
        if (pos && s[pos] == '?') rta = (rta * (ll)inv[pos])%MOD;
        s[pos] = c;
        if (pos && s[pos] == '?') rta = (rta * (ll)pos)%MOD;
        if (!pos && s[pos] == '?') nz = 0;
        cout << rta * nz << '\n';
    }

    return 0;
}
