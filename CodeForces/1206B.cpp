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

const int MAXN = 1e5+2;

int dp[MAXN][2];

int main() {
    FAST_IO;

    int N; cin >> N;
    int imp = 0,zero = 0; ll sum = 0;
    forn (i,N) {
        int x; cin >> x;
        if (!x) {dp[i][0] = dp[i][1] = 1; zero++;}
        else {
            dp[i][0] = (x < 0 ? abs(x)+1 : abs(x)-1);
            dp[i][1] = (x > 0 ? abs(x)+1 : abs(x)-1);
        }
        if (dp[i][1] < dp[i][0]) {imp++; sum += dp[i][1];}
        else sum += dp[i][0];
    }

    cout << sum+((imp & 1) and (!zero) ? 2 : 0);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!