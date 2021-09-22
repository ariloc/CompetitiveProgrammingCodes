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

const int MAXL = 26;

int interest[MAXL];
map<pair<ll,char>, int> found;

int main() {
    FAST_IO;

    forn (i,MAXL) cin >> interest[i];
    string s; cin >> s;

    ll sum = 0, rta = 0;
    forn (i,s.size()) {
        auto it = found.find({sum,s[i]});
        if (it != found.end()) rta += it->snd;
        sum += interest[s[i]-'a'];
        found[{sum,s[i]}]++;
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!