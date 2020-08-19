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

    int N; cin >> N;
    string a,b; cin >> b >> a;

    vi swaps;
    forn (i,N) {
        if (a[i] != b[i]) {
            vi tmp;
            bool posib = false;
            forsn(j,i+1,N) {
                tmp.pb(j);
                if (b[j] == a[i]) {posib = true; break;}
            }
            if (!posib) {cout << -1; return 0;}
            dforn (j,tmp.size()) {
                swaps.pb(tmp[j]);
                swap(b[tmp[j]-1],b[tmp[j]]);
            }
        }
    }


    cout << swaps.size() << '\n';
    for (auto &i : swaps) cout << i << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!