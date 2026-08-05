#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MOD = 1e6+3;
int const MAXN = MOD+5;
int const MAXG = 12;

int binExp(int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD;
        k >>= 1;
    }
    return r;
}

int ls[MAXN][MAXG];
int potDiv[MAXN];

int main() {
    FAST_IO;

    forsn(i,1,MAXN) potDiv[i] = binExp(i, MOD-2);

    // Lagrange mientras vas adivinando el grado
    vi rtas;
    forn(i,11) {
        cout << "? " << i << endl;
        int rta; cin >> rta;
        rtas.pb(rta);

        forn(x,MOD) {
            forn(j,i) {
                ls[x][j] = (ls[x][j] * (ll)((x-i+MOD)%MOD))%MOD;
                ls[x][j] = (ls[x][j] * (ll)potDiv[(j-i+MOD)%MOD])%MOD;
            }
            ls[x][i] = 1;
            forn(j,i) {
                ls[x][i] = (ls[x][i] * (ll)((x-j+MOD)%MOD))%MOD;
                ls[x][i] = (ls[x][i] * (ll)potDiv[(i-j+MOD)%MOD])%MOD;
            }
        }

        forn(x,MOD) {
            int ev = 0;
            forn(j,i+1)
                ev = (ev + (ls[x][j] * (ll)rtas[j])%MOD)%MOD;
            
            if (!ev) {
                cout << "? " << x << endl;
                int auxi; cin >> auxi;
                if (!auxi) {
                    cout << "! " << x << endl;
                    return 0;
                }
                else break;
            }
        }
    }

    vector<ii> pts;
    forn(i,11) {
        
    }

    
  
    cout << "! -1\n";

    return 0;
}
