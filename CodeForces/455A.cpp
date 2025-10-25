#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;

int cnt[MAXN];
ll dp[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x; cin >> x;
        cnt[x]++;
    }

    ll maxi = 0;
    forsn(i,1,MAXN) {
        dp[i] = dp[i-1];
        dp[i] = max(dp[i], (i >= 2 ? dp[i-2] : 0)+cnt[i]*(ll)i);
        maxi = max(maxi,dp[i]);
    }

    cout << maxi << '\n';

    return 0;

}
