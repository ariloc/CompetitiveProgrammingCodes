#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        string s; cin >> s;

        int idx = 1;
        forsn(i,1,s.size()) {
            if (s[i-1] < s[i]) {
                idx = i;
                break;
            }
        }

        string r;
        forn(i,idx) r.pb(s[i]);
        string r2;
        r2 = r;
        reverse(all(r));
        r2 += r;

        string r3;
        r3.pb(s[0]);
        r3.pb(s[0]);

        string r4,r5;
        idx = n;
        forn(i,idx) r4.pb(s[i]);
        r5 = r4;
        reverse(all(r4));
        r5 += r4;

        cout << min(r5, min(r3, r2)) << '\n';
    }

    return 0;
}
