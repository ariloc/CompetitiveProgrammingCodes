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

int const MAXN = 1005;

char mat[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) forn(j,m) cin >> mat[i][j];

    forn(j,m) {
        int cnt = 0;
        char prv = mat[n-1][j];
        dforn(i,n) {
            if (prv == mat[i][j]) ++cnt;
            else cnt = 1;
            dp[i][j] = cnt;
            prv = mat[i][j];
        }
    }

    ll rta = 0;
    forn(i,n) {
        int j = 0;
        while (j < m) {
            int ka = i;
            int kb = ka + dp[ka][j];
            if (kb >= n) {j++; continue;} 
            int kc = kb + dp[kb][j];
            if (kc >= n) {j++; continue;}

            int va = dp[ka][j], vb = dp[kb][j], vc = dp[kc][j];
            char ca = mat[ka][j], cb = mat[kb][j], cc = mat[kc][j];

            if (va != vb || vc < va || ca == cb || cb == cc) {
                ++j; continue;
            }

            int st = j+1;
            while (st < m) {
                int la = i;
                int lb = la + dp[la][st];
                if (lb >= n) break;
                int lc = lb + dp[lb][st];
                if (lc >= n) break;

                int va_cur = dp[la][st], vb_cur = dp[lb][st], vc_cur = dp[lc][st];
                char ca_cur = mat[la][st], cb_cur = mat[lb][st], cc_cur = mat[lc][st];

                if (va_cur != vb_cur || vc_cur < va_cur || ca_cur == cb_cur || cb_cur == cc_cur)
                    break;

                if (va_cur != va || vb_cur != vb || vc_cur < va || ca_cur != ca || cb_cur != cb || cc_cur != cc)
                    break;

                ++st;
            }

            rta += (st-j)*(st-j+1)/2;

            j = st;
        }
    }

    cout << rta << '\n';

    return 0;
}
