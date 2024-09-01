#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int const MAXN = 1005;

string const tlet[] = {
    "###",
    ".#.",
    ".#.",
    ".#.",
    ".#."
};

string const alet[] = {
    "###",
    "#.#",
    "###",
    "#.#",
    "#.#"
};

string const plet[] = {
    "###",
    "#.#",
    "###",
    "#..",
    "#.."
};

string mat[MAXN];
int n,m;

int doit(int mi, int mj, const string let[], int li, int lj) {
    vector<ii> toDel;
    forn(i,5) forn(j,3) {
        int di = i-li, dj = j-lj;
        int ti = mi + di, tj = mj + dj;
        if (let[i][j] == '#') {
            if(ti >= 0 && ti < n && tj >= 0 && tj < m && mat[ti][tj] == '#')
                toDel.pb({ti,tj});
            else return 0;
        }
    }
    for (auto &k : toDel)
        mat[k.fst][k.snd] = '.';
    return 1;
}

void dbg() {
    cerr << "!!!!!!!!!!!!!!!!!!!!!!!!!!1" << endl;
    forn(i,n) cerr << mat[i] <<  endl;
}

int main() {
    FAST_IO;

    cin >> n >> m;
    forn(i,n) cin >> mat[i];

    int t = 0, a = 0, p = 0;
    dforn(j,m) dforn(i,n) {
        if(doit(i,j,tlet,0,2)) {
            ++t;
        }
        if(doit(i,j,alet,4,2)) {
            ++a;
        }
        if(doit(i,j,plet,2,2)) {
            ++p;
        }
    }

    cout << t << ' ' << a << ' ' << p << '\n';


    return 0;
}
