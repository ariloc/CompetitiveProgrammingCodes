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

        vector<vector<vi>> rang(n,vector<vi>(m,vi(m,-1)));
    
        vector<vi> curang(m,vi(m,-1));
        forn(i,n) {
            forn(j,m) 
                if (table[i][j])
                    forsn(k,j+1,m) 
                        if (table[i][k])
                            curang[j][k] = i;
            rang[i] = curang;
        }

        
        vector<vi> rta(n,vi(m,0));
        forn(i,m) forn(j,m) curang[i][j] = -1;
        forn(i,n) forn(j,m) rta[i][j] = INF;
        dforsn(i,1,n) {
            forn(j,m)
                if (table[i][j])
                    forsn(k,j+1,m)
                        if (table[i][k])
                            curang[j][k] = i;

            forn(j,m) {
                int mini = INF;
                dforsn(k,j,m) {
                    if (curang[j][k] != -1 && rang[i-1][j][k] != -1) {
                        int prod = (curang[j][k]-rang[i-1][j][k]+1)*(k-j+1);
                        mini = min(mini,prod);
                    }
                    rta[i][k] = min(rta[i][k], mini);
                    rta[i-1][k] = min(rta[i-1][k], mini);
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
