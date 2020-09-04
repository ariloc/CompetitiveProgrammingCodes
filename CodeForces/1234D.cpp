#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 26;

set<int> let[MAXN];

int main() {
    FAST_IO;

    string s; cin >> s;
    forn(i,s.size()) let[s[i]-'a'].insert(i+1);
    int q; cin >> q;
    forn(i,q) {
        int typ; cin >> typ;
        if (typ == 2) {
            int l,r,cnt = 0; cin >> l >> r;
            forn(j,MAXN) {
                auto it = let[j].lower_bound(l);
                if (it != let[j].end() and *it <= r) cnt++;
            }
            cout << cnt << '\n';
        }
        else {
            int p; char c; cin >> p >> c;
            let[s[p-1]-'a'].erase(p);
            let[c-'a'].insert(p);
            s[p-1] = c;
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
