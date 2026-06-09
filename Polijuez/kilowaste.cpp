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

int const MAXR = 105;
int const MAXN = 5*1e4 + 2*MAXR + 5;
int const MAXP = 52;

bool dp[MAXN];
vi posib;

int main() {
    FAST_IO;

    int q,p; cin >> q >> p;

    dp[0] = true;
    forn(i,p) {
        int r; cin >> r;
        forsn(i,r,MAXN) dp[i] |= dp[i-r];
    }

    forn(i,MAXN) if(dp[i]) posib.pb(i);
    sort(all(posib));

    forn(_,q) {
        int n; cin >> n;
        int idx = lower_bound(all(posib),n)-posib.begin();
        cout << posib[idx]-n << '\n';
    }
       
    return 0;
}
