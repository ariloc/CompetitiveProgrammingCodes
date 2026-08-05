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

int const MAXN = 1005;
int const MAXS = 52;
int const MAXA = 26;
int const INF = 2e9+5;

int dp[2][MAXS][MAXS];

vi kmppre(string &t){
    vi r(t.size()+1);r[0]=-1;
    int j=-1;
    forn(i,t.size()){
        while(j>=0&&t[i]!=t[j])j=r[j];
        r[i+1]=++j;
    }
    return r;
}
int kmp(string &s, string &t){
    int j=0;vi b=kmppre(t);
    forn(i,s.size()){
        if(j==sz(t))j=b[j];
        while(j>=0&&s[i]!=t[j])j=b[j];
        ++j;
    }
    return j;
}

int main() {
    FAST_IO;

    string c; cin >> c;
    int n = sz(c);
    string s,t; cin >> s >> t;

    auto go = [&](int i){
        forn(j,min(i,sz(s)+1)) {
            string auxi;
            forn(k,j) auxi.pb(s[k]);
            auxi.pb(c[i-1]);
            int maxs = kmp(auxi, s);
            int maxt = kmp(auxi, t);

            forn(l,j+1)
                dp[i%2][maxs][maxt] = max(dp[i%2][maxs][maxt], dp[!(i%2)][j][l] + (maxs == sz(s)) - (maxt == sz(t)));
        }
        forn(j,min(i,sz(t))+1) {
            string auxi;
            forn(k,j) auxi.pb(t[k]);
            auxi.pb(c[i-1]);
            int maxs = kmp(auxi, s);
            int maxt = kmp(auxi, t);

            forn(l,j+1)
                dp[i%2][maxs][maxt] = max(dp[i%2][maxs][maxt], dp[!(i%2)][l][j] + (maxs == sz(s)) - (maxt == sz(t)));
        }
    };

    dp[0][0][0] = 0;
    forsn(i,1,n+1) {
        forn(j,MAXS) forn(k,MAXS) dp[i%2][j][k] = -INF;
        if (c[i-1] == '*') {
            forn(j,MAXA) {
                c[i-1] = j+'a';
                go(i);
            }
        }
        else go(i);
    }

    int maxi = -INF;
    forn(i,MAXS) forn(j,MAXS) maxi = max(maxi,dp[n%2][i][j]);

    cout << maxi << '\n';

    return 0;
}
