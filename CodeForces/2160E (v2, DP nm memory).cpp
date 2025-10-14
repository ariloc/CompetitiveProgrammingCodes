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
typedef long double ld;

int const INF = 2e9;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m; cin >> n >> m;
 
        vector<vector<bool>> table;
 
        forn(i,n) {
            table.pb({});
            string s; cin >> s;
            forn(j,m) {
                table[i].pb(s[j]-'0');
            }
        }
 
        bool trans = false;
        if (n < m) trans = true;
        
        if (trans) {
            swap(n,m);
            vector<vector<bool>> table2(n,vector<bool>(m));
            forn(i,n) forn(j,m) table2[i][j] = table[j][i];
            table = table2;
        }
 
        vector<vi> rta(n,vi(m,0));
        forn(i,n) forn(j,m) rta[i][j] = INF;
    
        forn(j,m) dforsn(k,j,m) {
            if (k+1 < m) forn(i,n) rta[i][k] = min(rta[i][k], rta[i][k+1]);
            int last = -1;
            if (k > j) forn(i,n) {
                if (table[i][j] && table[i][k]) {
                    if (last != -1) {
                        int prod = (i-last+1)*(k-j+1);
                        forsn(l,last,i+1)
                            rta[l][k] = min(rta[l][k], prod);
                    }
                    last = i;
                }
            }
        }

        if (trans)
            forn(i,m) forn(j,n) cout << (rta[j][i] == INF ? 0 : rta[j][i]) << " \n"[j == n-1];
        else
            forn(i,n) forn(j,m) cout << (rta[i][j] == INF ? 0 : rta[i][j]) << " \n"[j == m-1];
    }

    return 0;
}
