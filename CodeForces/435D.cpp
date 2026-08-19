#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 405;
int const INF = 1e9;
int const X[] = {1,-1,-1,1};
int const Y[] = {1,-1,1,-1};
int const DIAG[] = {0,0,1,1};
int const TAKE[] = {0,1,1,0};

int const CHK1[] = {0,0,1,1};
int const CHK2[] = {2,3,2,3};

char tab[MAXN][MAXN];
int diag[2][MAXN][MAXN];
bitset<MAXN> reg;
int n,m;

void godiag1(int i, int j){
    int ci = i, cj = j;
    int dist = INF;
    while (ci < n && cj >= 0) {
        if (tab[ci][cj] == '1') dist = 0;
        diag[0][ci][cj] = dist++;
        ++ci, --cj;
    }
}

void godiag2(int i, int j){
    int ci = i, cj = j;
    int dist = INF;
    while (ci < n && cj < m) {
        if (tab[ci][cj] == '1') dist = 0;
        diag[1][ci][cj] = dist++;
        ++ci, ++cj;
    }
}

int main() {
    FAST_IO;

    cin >> n >> m;
    forn(i,n) forn(j,m) cin >> tab[i][j];
    
    forsn(i,1,n) godiag1(i,m-1), godiag2(i,0);
    forn(i,m) godiag1(0,i), godiag2(0,i);

    ll rta = 0;
    forn(i,n) forn(j,m) {
        if (tab[i][j] == '1') continue;

        forn(k,4) {
            int ci = i + X[k], cj = j + Y[k], l = 1;
            while (ci >= 0 && ci < n && cj >= 0 && cj < m && tab[ci][j] == '0' && tab[i][cj] == '0') {
                if (diag[DIAG[k]][!TAKE[k] ? ci : i][TAKE[k] ? cj : j] > l) {
                    ++rta;
                }
                ci += X[k], cj += Y[k], ++l;
            }
        }

        forn(r,4) {
            reg.reset();
            int k1 = CHK1[r], k2 = CHK2[r];
            forn(q,2) {
                int k = q ? k2 : k1;
                int ci = i + X[k], cj = j + Y[k], l = 1;
                while (ci >= 0 && ci < n && cj >= 0 && cj < m) {
                    if (X[k1] != X[k2] && tab[ci][j] == '1') break;
                    if (Y[k1] != Y[k2] && tab[i][cj] == '1') break;
                    if (diag[DIAG[k]][!TAKE[k] ? ci : i][TAKE[k] ? cj : j] > l) {
                        if (!q) reg[l] = true;
                        else if (reg[l]) ++rta;
                    }
                    ci += X[k], cj += Y[k], ++l;
                }
            }
        }
    }

    cout << rta << '\n';

    return 0;
}
