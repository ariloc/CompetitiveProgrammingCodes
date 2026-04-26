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

int const MAXN = 55;
int const MOD = 1e9+7;

int mat[MAXN][MAXN];
int auxi[MAXN][MAXN];
int ans[MAXN][MAXN];

int main() {
    FAST_IO;

    int n; ll k; cin >> n >> k;

    forn(i,n) forn(j,n) cin >> mat[i][j];

    // Matrix Binary Exponentation
    forn(i,n) ans[i][i] = 1; // identity
    while (k) {
        if (k&1) {
            forn(i,n) forn(j,n) {
                auxi[i][j] = ans[i][j];
                ans[i][j] = 0;
            }
            forn(i,n) forn(j,n) forn(k,n)
                ans[i][j] = (ans[i][j] + (auxi[i][k] * (ll)mat[k][j])%MOD)%MOD;
        }

        forn(i,n) forn(j,n) {
            auxi[i][j] = mat[i][j];
            mat[i][j] = 0;
        }
        forn(i,n) forn(j,n) forn(k,n)
            mat[i][j] = (mat[i][j] + (auxi[i][k] * (ll)auxi[k][j])%MOD)%MOD;

        k >>= 1;
    }

    int s = 0;
    forn(i,n) forn(j,n) s = (s+ans[i][j])%MOD;

    cout << s << '\n';

    return 0;
}
