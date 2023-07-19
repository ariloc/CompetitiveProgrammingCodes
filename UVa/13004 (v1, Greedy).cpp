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

int const MAXDIG = 10;
int const MAXD = 20;

int histo[MAXDIG];
ll pot10[MAXD];

int main() {
    pot10[0] = 1;
    forsn(i,1,MAXD) pot10[i] = pot10[i-1] * 10LL;

    ll u;
    while (scanf("%lld",&u) != -1) {
        ll auxi = u;
        vi decomp;
        while (auxi) decomp.pb(auxi%10), auxi /= 10;
        reverse(all(decomp));

        forn(i,MAXDIG) histo[i] = 0;

        ll maxi = 0; int dig = 9, use = 0;
        forn(i,decomp.size()-1) {
            maxi *= 10, maxi += dig;
            use++;
            if (use >= 2) dig--, use = 0;
        }

        int n = (int)decomp.size();
        forn(i,decomp.size()) {
            forn(j,MAXDIG) histo[j] = 0;

            bool posib = true;
            ll aux = 0;
            forn(j,i) {
                aux += (decomp[j]*pot10[n-j-1]);
                histo[decomp[j]]++;
                if (histo[decomp[j]] > 2) posib = false;
            }
            if (!posib) break;

            bool done = false;
            dforn(j,decomp[i]) if (histo[j] < 2) {
                histo[j]++, aux += j*pot10[n-i-1], done = true; break;
            }
            if (!done) continue;

            forsn(j,i+1,decomp.size()) {
                dforn(k,MAXDIG) if (histo[k] < 2) {
                    histo[k]++, aux += k*pot10[n-j-1]; break;
                }
            }

            maxi = max(maxi, aux);
        }

        forn(i,MAXDIG) histo[i] = 0;
        bool isok = true;
        for (auto &i : decomp) {
            histo[i]++;
            if (histo[i] > 2) isok = false;
        }
        if (isok) maxi = max(maxi,u);

        printf("%lld\n",maxi);
    }
        
    return 0;
}
