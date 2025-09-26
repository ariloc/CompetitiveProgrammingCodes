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

int const MAXN = 2e5+5;
int const INF = 2e9;

ll inviz[MAXN][2], invder[MAXN][2];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        string s; cin >> s;

        int cnt[2] = {0,0};
        ll op[2] = {0,0};

        forn(i,n) {
            cnt[s[i]-'a']++;
            if (s[i] == 'b') op[0] += cnt['a'-'a'];
            else op[1] += cnt['b'-'a'];
            inviz[i][0] = op[0];
            inviz[i][1] = op[1];
        }
        cnt[0] = cnt[1] = 0;
        op[0] = op[1] = 0;
        dforn(i,n) {
            cnt[s[i]-'a']++;
            if (s[i] == 'b') op[0] += cnt['a'-'a'];
            else op[1] += cnt['b'-'a'];
            invder[i][0] = op[0];
            invder[i][1] = op[1];
        }

        ll mini = min(inviz[n-1][0], inviz[n-1][1]);
        forn(i,n-1) {
            mini = min(mini, inviz[i][0] + invder[i+1][0]);
            mini = min(mini, inviz[i][1] + invder[i+1][1]);
        }

        cout << mini << '\n';
    }

    return 0;
}
