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

const int MAXN = 1e6, MAXK = 9;

int tabla[MAXN][MAXK];
int dp[MAXN];

int product (int &x) {
    char c[10];
    sprintf(c,"%d",x);
    int r = c[0]-'0';
    for (int i = 1; c[i]; i++)
        if (c[i]-'0') r*=(c[i]-'0');
    return r;
}

int query (int n) {
    if (n < 10) return n;
    if (dp[n]) return dp[n];
    dp[n] = query(product(n));
    return dp[n];
}

int cnt[MAXK];

int main() {
    FAST_IO;

    forn (i,MAXN) {
        int act = query(i+1);
        cnt[act-1]++;
        forn (j,MAXK)
            tabla[i][j] = cnt[j];
    }

    int n;
    cin >> n;

    forn(i,n) {
        int l,r,x,cnt = 0;
        cin >> l >> r >> x;
        l-=2; r--; x--;

        cout << tabla[r][x]-(l < 0 ? 0 : tabla[l][x]) << '\n';
    }

    return 0;
}