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

const int MAXN = 500;

ii elem[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        memset(elem,0,sizeof(elem));

        int N; cin >> N;
        forn (j,N) cin >> elem[j].fst;
        int a = 0;
        forn (j,N) {cin >> elem[j].snd; a += elem[j].snd;}

        if (a == N or !a) {
            bool posib = true;
            forsn (j,1,N) if (elem[j].fst < elem[j-1].fst) {posib = false; break;}
            if (posib) cout << "Yes\n";
            else cout << "No\n";
        } else cout << "Yes\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!