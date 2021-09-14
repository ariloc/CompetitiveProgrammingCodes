#include <bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forsn(i,s,n) for (int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for (int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 105;
const int INF = 1e9;

int arr[MAXN],dp[MAXN][2],P[MAXN][2]; // B,R

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        forn(i,MAXN) dp[i][0] = dp[i][1] = INF;

        int n; cin >> n;
        string s; cin >> s;

        if (s[0] == '?') dp[0][0] = dp[0][1] = 0;
        else if (s[0] == 'B') dp[0][0] = 0;
        else dp[0][1] = 0;

        forsn(i,1,n) {
            if (s[i] == '?' || s[i] == 'B') {
                if (dp[i-1][0]+1 < dp[i-1][1])
                    dp[i][0] = dp[i-1][0]+1, P[i][0] = 0;
                else dp[i][0] = dp[i-1][1], P[i][0] = 1;
            }
            if (s[i] == '?' || s[i] == 'R') {
                if (dp[i-1][1]+1 < dp[i-1][0])
                    dp[i][1] = dp[i-1][1]+1, P[i][1] = 1;
                else dp[i][1] = dp[i-1][0], P[i][1] = 0;
            }
        }

        string r;
        int ind = (s[n-1] == '?' ? !(dp[n-1][0] < dp[n-1][1]) : s[n-1] == 'R');
        dforn(i,n) r.pb(ind ? 'R' : 'B'), ind = P[i][ind];
        
        reverse(all(r));
        cout << r << '\n';
    }
    
    return 0;
}