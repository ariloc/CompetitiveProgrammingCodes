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

const int MAXN = 1005;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        set<int> arr;

        int n,m; cin >> n >> m;

        int common = -1;
        forn(j,n) {int x; cin >> x; arr.insert(x);}
        forn(j,m) {int y; cin >> y; if (arr.count(y)) common = y;}

        if (common == -1) cout << "NO\n";
        else cout << "YES\n1 " << common << '\n';
    }

    return 0;
}

/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!