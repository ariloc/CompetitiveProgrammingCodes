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

const int MAXN = 2010;

bitset<MAXN> can;

int main() {
    FAST_IO;

    int p,N; cin >> N >> p;
    string s; cin >> s;
    forn (i,N) if (s[i] == '.') can[i] = true;
    forn (i,N) if (can[i]) s[i] = '1';

    bool posib = false;
    forn (i,N) {
        if (i+p < N and s[i] == s[i+p] and (can[i] or can[i+p])) {
            if (can[i+p]) s[i+p] = (s[i] == '1' ? '0' : '1');
            else s[i] = (s[i+p] == '1' ? '0' : '1');
            posib = true; break;
        }
        if (i+p < N and s[i] != s[i+p]) {posib = true; break;}
    }

    if (posib) cout << s;
    else cout << "No";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!