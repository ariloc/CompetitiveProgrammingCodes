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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n,m,a,b; cin >> n >> m >> a >> b;

        vector<vector<bool>> mat(n,vector<bool>(m));

        // height of shifted block is b, width is a

        if (a*n != b*m) {cout << "NO\n"; continue;}

        int d;
        forsn (j,1,m) if (!((j*n) % m)) {d = j; break;}

        int st = 0;
        forn (j,n) {
            for (int k = st, cnt = 0; cnt < a; cnt++, k++)
                {k %= m; mat[j][k] = 1;}
            st += d;
        }

        cout << "YES\n";
        forn (j,n) {forn (k,m) cout << mat[j][k]; cout << '\n';}
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!