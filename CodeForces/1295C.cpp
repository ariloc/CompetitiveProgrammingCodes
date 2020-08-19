#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int r = 0;
        string s,t;
        cin >> s >> t;

        int dp[s.size()+2][26]; // 0 is INF, otherwise there's a letter

        forn (i,s.size()+2)
            forn (j,26) dp[i][j] = 0;

        dforn (j,s.size()) {
            forn (k,26)
                dp[j][k] = dp[j+1][k];
            dp[j][s[j]-'a'] = j+1;
        }

        int indS = 0; bool posib = true;
        forn (j,t.size()) {
            if (dp[indS][t[j]-'a']) indS = dp[indS][t[j]-'a'];
            else if (!indS) posib = false;
            else {j--; r++; indS = 0;}
        }
        if (indS) r++;
        if (!posib) cout << -1 << '\n';
        else cout << r << '\n';
    }

    return 0;
}