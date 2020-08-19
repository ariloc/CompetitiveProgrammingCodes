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

const int MAXN = 52;

bool doneC[MAXN], doneF[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        memset(doneC,0,sizeof(doneC));
        memset(doneF,0,sizeof(doneF));
        int a,b; cin >> a >> b;

        int col = b, fil = a;
        forn(j,a) forn(k,b) {
            int x; cin >> x;
            if (x) {
                if (!doneC[k]) {doneC[k] = true; col--;}
                if (!doneF[j]) {doneF[j] = true; fil--;}
            }
        }

        if (min(col,fil) & 1) cout << "Ashish\n";
        else cout << "Vivek\n";

    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!