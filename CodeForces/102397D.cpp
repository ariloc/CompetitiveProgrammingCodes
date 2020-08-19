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

const int MAXN = 1e5+2;
const int INF = 1e9+2;

int street[MAXN];

int main() {
    FAST_IO;

    int n,x; cin >> n >> x;
    forn (i,n) cin >> street[i];

    int j = 0, sum = 0, r = INF;
    forn (i,n) {
        while (j < n and sum < x)
            sum += street[j++];

        if (sum >= x and j-i < r) r = j-i;

        sum -= street[i];
    }

    cout << (r == INF ? -1 : r);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!