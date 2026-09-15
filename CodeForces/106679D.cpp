#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;

int const MAXN = 1005;

vector<string> tab;

vector<string> flip(vector<string> boa) {
    vector<string> ret;
    forn(i,sz(boa)) {
        ret.pb("");
        dforn(j,sz(boa[0])) ret.back().pb(boa[i][j]);
    }
    return ret;
}

vector<string> rot90(vector<string> boa) {
    int n = sz(boa), m = sz(boa[0]);
    vector<string> ret(m,string(n,'.'));
    forn(i,n) forn(j,m) ret[j][n-i-1] = boa[i][j];
    return ret;
}

vector<string> rotm90(vector<string> boa) {
    int n = sz(boa), m = sz(boa[0]);
    vector<string> ret(m,string(n,'.'));
    forn(i,n) forn(j,m) ret[m-j-1][i] = boa[i][j];
    return ret;
}

vector<string> rot180(vector<string> boa) {
    int n = sz(boa), m = sz(boa[0]);
    vector<string> ret(n,string(m,'.'));
    forn(i,n) forn(j,m) ret[n-i-1][m-j-1] = boa[i][j];
    return ret;
}

bool check(vector<string> a, vector<string> b) { // rot,  orig
    if (sz(a) != sz(b)) return false;
    if (sz(a[0]) != sz(b[0])) return false;
    forn(i,sz(a)) forn(j,sz(a[0])) if (a[i][j] == '.' && b[i][j] == '#') return false;
    return true;
}

int main() {
    FAST_IO;
    
    int n,m; cin >> n >> m;
    forn(i,n) {
        string s; cin >> s;
        tab.pb(s);
    }

    int cnt = 1;
    if (check(rot90(tab),tab)) cnt++;
    if (check(rotm90(tab),tab)) cnt++;
    if (check(rot180(tab),tab)) cnt++;
    if (check(flip(tab),tab)) cnt++;
    if (check(flip(rot90(tab)),tab)) cnt++;
    if (check(flip(rotm90(tab)),tab)) cnt++;
    if (check(flip(rot180(tab)),tab)) cnt++;

    cout << cnt << '\n';

    return 0;
}
