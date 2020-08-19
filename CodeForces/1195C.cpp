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

const int MAXN = 2e5+50;
const int MARGIN = 10;

ll dp[MAXN*2];
ll fila[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) cin >> fila[i*2+MARGIN];
    forn (i,N) cin >> fila[i*2+1+MARGIN];

    //forn (i,MARGIN) dp[i] = 0;
    forsn (i,MARGIN,N*2+MARGIN) {
        if (i & 1) dp[i] = max(dp[i-3],dp[i-5])+fila[i];
        else dp[i] = max(dp[i-1],dp[i-3])+fila[i];
    }

    ll maxi = -1;
    dforn (i,N*2+MARGIN) maxi = max(maxi,dp[i]);

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!