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

const int MOD = 1e9+7;
const int MAXB = 6;
const int MAXN = 2e5+5;

int arr[MAXN],dp[2][1<<MAXB];
int pot2[MAXN];

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    FAST_IO;

    pot2[0] = 1;
    forsn(i,1,MAXN) pot2[i] = sumMod(pot2[i-1], pot2[i-1]);

    int t; cin >> t;
    forn(_,t) {
        int n,k; cin >> n >> k;
        forn(i,n) cin >> arr[i];

        forn(i,1<<MAXB) dp[0][i] = dp[1][i] = 0;

        forn(i,n) {
            forn(j,1<<MAXB) dp[i&1][j] = dp[1^(i&1)][j];
            forn(j,1<<MAXB) 
                dp[i&1][arr[i]&j] = sumMod(dp[i&1][arr[i]&j], dp[1^(i&1)][j]);
            
            dp[i&1][arr[i]] = sumMod(dp[i&1][arr[i]],1);
        }

        int rta = 0;
        forn(i,1<<MAXB) {
            if (__builtin_popcount(i) == k) {
                rta = sumMod(rta, dp[(n-1)&1][i]);
            }
        }

        cout << rta << '\n';
    }
  
    return 0;
}
