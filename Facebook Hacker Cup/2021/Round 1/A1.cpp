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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 8e5+5;
const int INF = 1e9+5;

int dp[MAXN][2]; // letra, mano

int main() {
    FAST_IO;

    freopen("weak_typing_chapter_1_input.txt","r",stdin);
    freopen("salida.txt","w",stdout);

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        string s; cin >> s;

        forn(i,n+1) dp[i][0] = dp[i][1] = INF;
        if (s[0] == 'F') dp[0][0] = dp[0][1] = 0;
        if (s[0] == 'X') dp[0][0] = 0;
        if (s[0] == 'O') dp[0][1] = 0;

        forsn(i,1,n) {
            if (s[i] == 'F' || s[i] == 'X') dp[i][0] = min(dp[i-1][0],dp[i-1][1]+1);
            if (s[i] == 'F' || s[i] == 'O') dp[i][1] = min(dp[i-1][1],dp[i-1][0]+1);
        }

        cout << "Case #" << o+1 << ": " << min(dp[n-1][0],dp[n-1][1]) << '\n';
    }

    return 0;
}