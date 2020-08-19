#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+2;

int a[MAXN];
ii b[MAXN];
int dp[MAXN], rta[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,n) cin >> a[i];
    forn (i,m) {cin >> b[i].fst; b[i].snd = i;}

    sort(b,b+m);

    forn (i,n) {
        int low = -1, high = m;
        int x = a[i];

        while (high-low > 1) {
            int mid = (high+low)/2;
            if (b[mid].fst >= x) high = mid;
            else low = mid;
        }
        if (!high and x > b[high].fst) continue;
        dp[high]++;
    }

    forsn (i,1,m) dp[i] += dp[i-1];
    forn (i,m) rta[b[i].snd] = dp[i];

    forn (i,m) cout << rta[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!