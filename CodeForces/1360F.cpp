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
const int MAXL = 26;

bool difs (string &a, string &b) {
    int cnt = 0;
    forn (i,a.size()) {
        if (a[i] != b[i]) cnt++;
    }
    if (cnt > 1) return false;
    return true;
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        vector<string> S;
        int n,m; cin >> n >> m;

        forn (j,n) {
            string s; cin >> s;
            S.pb(s);
        }

        string base = S[0];

        forn (j,m) {
            forn (k,MAXL) {
                bool posib = true;
                base[j] = k+'a';
                forn (o,n) {
                    if (!difs(S[o],base)) {posib = false; break;}
                }
                if (posib) {cout << base << '\n'; goto END;}
            }
            base[j] = S[0][j];
        }

        cout << "-1\n";
        END: continue;
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!