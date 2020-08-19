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

const int MAXN = 2e5+2;

ll dpL[MAXN],dpR[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    ll rta = 0;
    forn(i,N) {cin >> dpL[i]; dpR[i] = dpL[i];}
    forsn(i,1,N) dpL[i] += dpL[i-1];
    dforn(i,N-1) dpR[i] += dpR[i+1];

    int j = N-1;
    forn (i,N) {
        while (j > i and dpR[j] <= dpL[i]) j--;
        if (dpL[i] == dpR[j+1]) rta = max(rta,dpL[i]);
        if (j <= i) break;
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!