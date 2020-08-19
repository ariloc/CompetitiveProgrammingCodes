#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int q;
    cin >> q;

    forn (i,q) {
        int n,m;
        cin >> n >> m;
        int LTemp = m, RTemp = m, tiempo = 0;
        bool posib = true;
        forn (j,n) {
            int t,l,r;
            cin >> t >> l >> r;

            int difT = t-tiempo;
            int LRange = LTemp - difT, RRange = RTemp + difT;
            if (!((LRange >= l and LRange <= r) or (RRange >= l and RRange <= r) or (LRange <= l and RRange >= r)))
                posib = false;
            LTemp = max(LRange,l); RTemp = min(RRange,r);
            tiempo = t;
        }

        if (posib) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }

    return 0;
}