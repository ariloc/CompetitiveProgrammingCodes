#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXB = 24;

int dp[1<<MAXB];

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n) {
        string s; cin >> s;
        int mk = 0;
        forn(j,sz(s)) mk |= (1<<(s[j]-'a'));
        dp[mk]++;
    }

    forn(i,MAXB) forn(mk,1<<MAXB)
        if (mk&(1<<i)) dp[mk] += dp[mk^(1<<i)];

    int rta = 0;
    forn(mk,1<<MAXB) {
        int val = n - dp[mk];
        rta ^= (val*val);
    }

    cout << rta << '\n';

    return 0;
}
