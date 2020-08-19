#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;
const ll INF = 9e18+2;

int col[3][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int cant[3]; cin >> cant[0] >> cant[1] >> cant[2];
        ll rta = INF;

        forn (j,3)
            forn (k,cant[j]) cin >> col[j][k];

        // Considering possibilites a <= b <= c. Me acerco ,lo más posible al medio.
        forn (j,3) sort(col[j],col[j]+cant[j]);

        forn (j,3) {
            forn (k,cant[j]) {
                int e = col[j][k];
                int r = j+1, l = j-1;
                if (l < 0) l = 2;
                r %= 3;

                forn (o,2) {
                    if (o&1) swap(r,l);
                    auto x = lower_bound(col[l],col[l]+cant[l],e);
                    auto z = lower_bound(col[r],col[r]+cant[r],e);
                    if (z-col[r] >= cant[r] or (x-col[l] <= 0 and x[0] != e))
                        continue;
                    if (col[l][(x-col[l])] > e or x-col[l] >= cant[l]) x--;
                    rta = min(rta, (ll)(*x-e)*(*x-e) + (ll)(e-*z)*(e-*z) + (ll)(*z-*x)*(*z-*x) );
                }
            }
        }

        cout << rta << '\n';
    }

    return 0;
}