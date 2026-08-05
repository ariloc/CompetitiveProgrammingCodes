#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) (int)c.size()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int const MAXN = 205;

int mat[MAXN][MAXN];
bitset<MAXN> rowsd, rowsu;
bitset<MAXN> posibu, posibd;
bitset<MAXN> cur, prvd, prvu;

int main(){
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) forn(j,m) cin >> mat[i][j];

    if (n == 1) {
        cout << "YES\n" << "0\n";
        forn(i,m) cout << mat[0][i];
        cout << '\n';
        return 0;
    }

    posibu[0] = true; posibd[n-1] = true;
    forn(i,m) prvu[i] = mat[0][i];
    forsn(i,1,n) {
        cur.reset();
        forn(j,m) cur[j] = mat[i][j];
        if (cur == prvu) posibu[i] = true;
        else {
            forn(j,m) cur[j] = 1^cur[j];
            if (prvu != cur) break;
            rowsu[i] = true;
            posibu[i] = true;
        }
    }
    forn(i,m) prvd[i] = 1^mat[n-1][i];
    dforn(i,n-1) {
        cur.reset();
        forn(j,m) cur[j] = 1^mat[i][j];
        if (cur == prvd) posibd[i] = true;
        else {
            forn(j,m) cur[j] = 1^cur[j];
            if (prvd != cur) break;
            rowsd[i] = true;
            posibd[i] = true;
        }
    }

    forn(i,n) {
        if (i && !posibu[i-1]) continue;
        if (i < n-1 && !posibd[i+1]) continue;
        cur.reset();
        forn(j,m) cur[j] = 1^mat[i][j];
        forn(j,m+1) {
            bitset<MAXN> prvd_cpy, prvu_cpy;
            prvd_cpy = prvd; prvu_cpy = prvu;
            forn(l,2) {
                forn(k,2) {
                    if ((!i || cur == prvu_cpy) && (i == n-1 || cur == prvd_cpy)) {
                        forsn(r,i+1,n) rowsu[r] = rowsd[r];
                        rowsu[i] = false;

                        cout << "YES\n";
                        forn(r,n) cout << rowsu[r];
                        cout << '\n';
                        if (i) forn(r,m) cout << prvu_cpy[r];
                        else forn(r,m) cout << prvd_cpy[r];
                        cout << '\n';
                        return 0;
                    }
                    forn(r,m) prvu_cpy[r] = 1^prvu_cpy[r];
                    rowsu = ~rowsu;
                }
                forn(r,m) prvd_cpy[r] = 1^prvd_cpy[r];
                rowsd = ~rowsd;
            }
            if (j < m) cur[j] = mat[i][j];
        }
    }

    cout << "NO\n";

    return 0;
}
