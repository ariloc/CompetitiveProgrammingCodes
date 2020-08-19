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

const int INF = 1e9+2;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int N; cin >> N;
        set<ii> arr;
        vi saved;
        bool posib = false;
        forn (j,N) {
            int x; cin >> x; saved.pb(x);
        }
        forn (j,N) {
            auto it = arr.lower_bound({saved[j],-INF});
            if (it != arr.begin() and (*(prev(it))).fst < saved[j]) {
                forsn(k,j+1,N) {
                    if (saved[k] < saved[j]) {
                        cout << "YES\n";
                        cout << (*(prev(it))).snd+1 << ' ' << j+1 << ' ' << k+1 << '\n';
                        posib = true; break;
                    }
                }
            }
            if (posib) break;

            arr.insert({saved[j],j});
        }
        if (!posib) cout << "NO\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!