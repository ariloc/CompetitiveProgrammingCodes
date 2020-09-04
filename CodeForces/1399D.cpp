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

const int INF = 1e9+5;
const int MAXN = 2e5+5;

int rta[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        multiset<pair<bool,int>> seq;

        int n; cin >> n;
        string s; cin >> s;
        int am = 0;
        forn (j,s.size()) {
            bool me = (s[j] == '1');
            auto it = seq.lower_bound({!me,-INF});
            if (it == seq.end() or (*it).fst == me) {rta[j] = ++am; seq.insert({me,am});}
            else {
                rta[j] = (*it).snd;
                seq.insert({me,rta[j]});
                seq.erase(it);
            }
        }
        cout << am << '\n';
        forn(j,s.size()) cout << rta[j] << ' ';
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
