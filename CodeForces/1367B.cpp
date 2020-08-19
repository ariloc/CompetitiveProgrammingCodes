#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn (i,t) {
        int N; cin >> N;
        int noImp = 0, noPar = 0;
        forn (j,N) {
            int x; cin >> x;
            if ((x & 1) != (j & 1)) {
                if (j & 1) noImp++;
                else noPar++;
            }
        }
        if (noImp != noPar) cout << "-1\n";
        else cout << noImp << '\n';
    }

    return 0;
}