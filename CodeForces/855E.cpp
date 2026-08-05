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

int const MAXB = 11;
int const MAXD = 63;

ll dp1[MAXB][MAXD][1<<MAXB];
ll dp2[MAXB][MAXD][1<<MAXB];

ll calc(ll num, int b) {
    if (!num) return 0;
    vi trans;
    while (num > 0) { trans.pb(num%b); num /= b; }
    reverse(all(trans));
    ll r = 0, curmk = 0;
    forsn(i,1,sz(trans)) r += dp1[b][i][0];
    forn(i,sz(trans)) {
        forsn(j,(i==0),trans[i]) r += dp2[b][sz(trans)-i-1][curmk^(1<<j)];
        curmk ^= 1<<trans[i];
    }
    if (!curmk) r++;
    return r;
}

int main() {
    FAST_IO;

    forsn(b,2,MAXB) {
        forsn(i,1,b) dp1[b][1][1<<i] = 1;
        forsn(i,2,MAXD) {
            forn(mk,1<<b) {
                forn(k,b) {
                    dp1[b][i][mk] += dp1[b][i-1][mk^(1<<k)];
                }
            }
        }
    }

    forsn(b,2,MAXB) {
        dp2[b][0][0] = 1;
        forsn(i,1,MAXD) {
            forn(mk,1<<b) {
                forn(k,b) {
                    dp2[b][i][mk] += dp2[b][i-1][mk^(1<<k)];
                }
            }
        }
    }

    int q; cin >> q;
    forn(_,q) {
        int b; ll l,r; cin >> b >> l >> r;
    
        ll sl = calc(l-1,b), sr = calc(r,b);
        cout << sr - sl << '\n';
    }

    return 0;
}
