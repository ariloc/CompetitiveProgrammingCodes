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

const int MAXN = 26;

ll DP[MAXN][MAXN];
ll DP1[MAXN];

int main() {
    FAST_IO;

    string s;
    cin >> s;

    ll best = 0;

    forn (i,s.size()) {
        forn (j,MAXN) {
            if (DP1[j]) {
                DP[j][s[i]-'a']+=DP1[j];
                best = max(best,DP[j][s[i]-'a']);
            }
        }
        DP1[s[i]-'a']++;
        best = max(best,DP1[s[i]-'a']);
    }

    cout << best << endl;

    return 0;
}