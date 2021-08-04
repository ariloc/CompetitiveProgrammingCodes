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

const int MAXN = 105;

vector<string> sopa;
vector<string> inv;
vector<string> pal;
bitset<MAXN> done;

int main() {
    FAST_IO;

    int N,M,k; cin >> N >> M >> k;
    inv.resize(M);
    forn (i,N) {
        string s; cin >> s; sopa.pb(s);
        forn (j,s.size()) inv[j] += s[j];
    }
    forn (i,k) {string s; cin >> s; pal.pb(s);}

    forn (o,2) {
        forn (i,k) {
            forn (j,N) {
                if (sopa[j].find(pal[i]) != string::npos) done[i] = true;
            }
            forn (j,M) {
                if (inv[j].find(pal[i]) != string::npos) done[i] = true;
            }
        }
        if (!(o&1)) {
            forn (j,N) reverse(all(sopa[j]));
            forn (j,M) reverse(all(inv[j]));
        }
    }

    forn (i,k) cout << (done[i] ? "SI" : "NO") << '\n';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!