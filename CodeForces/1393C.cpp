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

const int MAXN = 2e5+5;
const int INF = 1e9+5;

int freq[MAXN], order[MAXN], ind = 0;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        forn (j,MAXN) freq[j] = 0; ind = 0;
        int n; cin >> n;

        forn (j,n) {
            int x; cin >> x;
            freq[x-1]++;
        }

        int cant = 0;
        dforn (j,MAXN) if (freq[j]) order[ind++] = freq[j];
        sort(order,order+ind);

        int maxi = order[ind-1];
        dforn (j,ind-1) cant += order[j]-(order[j] == maxi);

        int cont = cant/(maxi-1); // distrib óptima

        cout << cont << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!