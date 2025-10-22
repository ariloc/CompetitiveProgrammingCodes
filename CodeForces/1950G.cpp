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

int const MAXN = 16;

string gs[MAXN],wrs[MAXN];
vector<string> gens,wris;
int g[MAXN],w[MAXN];
bool dp[MAXN][1<<MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> gs[i] >> wrs[i];

        gens.clear(); wris.clear();

        forn(i,n) gens.pb(gs[i]), wris.pb(wrs[i]);
        sort(all(gens));
        sort(all(wris));
        gens.erase(unique(all(gens)),gens.end());
        wris.erase(unique(all(wris)),wris.end());

        forn(i,n) {
            g[i] = lower_bound(all(gens),gs[i])-gens.begin();
            w[i] = lower_bound(all(wris),wrs[i])-wris.begin();
        }

        forn(i,n) forn(mk,1<<n) dp[i][mk] = false;
        forn(i,n) dp[i][1<<i] = true;

        forn(mk,1<<n) forn(i,n) if (mk&(1<<i)) forn(j,n) if (j != i && mk&(1<<j)) {
            if (w[i] == w[j] || g[i] == g[j])
                dp[i][mk] |= dp[j][mk^(1<<i)];
        }

        int mini = n-1;
        forn(i,n) forn(mk,1<<n) if (dp[i][mk]) mini = min(mini, n-__builtin_popcount(mk));

        cout << mini << '\n';
    }

    return 0;
}
