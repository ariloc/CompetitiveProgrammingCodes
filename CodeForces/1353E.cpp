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

const int MAXN = 1e6+2;
const int INF = 1e9+2;

struct range{
    int l,r,cnt;
};

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        int sum = 0;
        forn (j,n) sum += (s[j] == '1');

        // Kadane, I'll consider 1s as +1, and 0s as -1
        // En el subarray de los elementos de resto k, el de menor pérdida resto menos
        int rta = sum;
        forn (j,k) {
            int accum = 0;
            for (int p = j; p < n; p += k) {
                accum += (s[p] == '1' ? 1 : -1);
                if (accum < 0) accum = 0;
                rta = min(rta,sum-accum);
            }
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!