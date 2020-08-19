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

const int INF = 1e9+2;
const int MAXN = 1e6+15;

int dp[MAXN];

int main() {
    FAST_IO;

    forn (i,MAXN) dp[i] = INF;

    int N; cin >> N;

    dp[0] = 0;
    forn (i,N) {
        if (dp[i] == INF) continue;
        int num = N-i;
        //cerr << num << endl;
        while (num) {
            int high = (num % 10);
            dp[i+high] = min(dp[i+high],dp[i]+1);
            num /= 10;
        }
    }

    cout << dp[N];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!