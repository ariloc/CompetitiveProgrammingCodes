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

int const X[] = {0,1,-1,0};
int const Y[] = {1,0,0,-1};
int const MAXR = 1005;
int const MAXC = 105;

bitset<MAXC> mat[MAXR];
bitset<MAXC> shifts[MAXC], done[MAXR];
int r,c;

bool solve(bitset<MAXC> act) {
    forn(i,c) forn(j,c) shifts[i][j] = act[(j+i)%c];
    forn(i,r+1) done[i].reset();

    queue<ii> Q;
    forn(i,c) if (!(shifts[i]&mat[0]).count()) done[0][i] = true, Q.push({0,i});

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        forn(k,4) {
            int tY = e.fst + Y[k], tX = (e.snd + X[k] + c)%c;
            if (done[tY][tX]) continue;
            if (tY < 0 || tY >= r) continue;
            if ((shifts[tX]&mat[tY]).count()) continue;
            done[tY][tX] = true;
            Q.push({tY,tX});
        }
    }

    bool posib = false;
    forn(i,c) posib |= done[r-1][i];
    return posib;
}

int main() {
    FAST_IO;

    cin >> r >> c;

    string s; cin >> s;
    bitset<MAXC> act;
    forn(i,c) act[i] = (int)(s[i]-'0');

    forn(i,r) {
        string aux; cin >> aux;
        forn(j,c) mat[i][j] = (int)(aux[j]-'0');
    }

    bool posib = solve(act);
    bitset<MAXC> aux;
    forn(i,c) aux[i] = act[c-i-1];
    posib |= solve(aux);

    cout << (posib ? "Y" : "N") << '\n';

    return 0;
}
