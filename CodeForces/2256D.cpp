#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MOD = 998244353;

int const MAXN = 2e6+5;

int fact[MAXN], inv[MAXN], invfact[MAXN], pot[MAXN];

int main() {
    FAST_IO;

    fact[0] = 1, inv[1] = 1, invfact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1] * (ll)i)%MOD;
    forsn(i,2,MAXN) inv[i] = MOD - ((ll)(MOD/i) * inv[MOD%i])%MOD;
    forsn(i,1,MAXN) invfact[i] = (invfact[i-1] * (ll)inv[i])%MOD;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        string s; cin >> s;
        
        int cnt0 = 0, cnt1 = 0;
        forn(i,sz(s)) if (s[i] == '0') cnt0++; else cnt1++;

        int g0 = 0, g1 = 0;
        forsn(i,1,sz(s)) {
            if (s[i] != s[i-1]) {
                if (s[i-1] == '0') g0++;
                else g1++;
            }
        }
        if (s.back() == '0') g0++;
        else g1++;

        if (!g0 || !g1) {
            cout << "1\n";
            continue;
        }

        int val0 = ((fact[cnt0-1] * (ll)invfact[cnt0-g0])%MOD * (ll)invfact[g0-1])%MOD;
        int val1 = ((fact[cnt1-1] * (ll)invfact[cnt1-g1])%MOD * (ll)invfact[g1-1])%MOD;

        //cerr << val0 << ' ' << cnt0 << ' ' << g0 << endl;
        //cerr << val1 << ' ' << cnt1 << ' ' << g1 << endl;

        cout << (val0 * (ll)val1)%MOD << '\n';
    }

    return 0;
}
