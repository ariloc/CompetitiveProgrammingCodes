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

const int MAXN = 5005;
const int INF = 1e9+5;

int arr[MAXN];

int solve(int l, int r, int h) {
    //cerr << l << ' ' << r << ' ' << h << endl;
    if (l >= r) return 0; // caso 0
    int mini = INF, ind = -1; bool uniform = true;
    forsn(i,l,r) { // mientras este todo a nivel
        if (mini > arr[i]) {mini = arr[i]; ind = i;} // de lo contrario
        if (i+1 <= r and arr[i] != arr[i+1]) uniform = false; // si no es todo uniforme
    }
    if (uniform) return max(0,mini-h); // de lo contrario no hay discusión en la mejor rta (y no me voy de largo)
    return min(solve(l,ind,mini) + solve(ind+1,r,mini) + mini-h, r-l);
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn (i,n) cin >> arr[i];

    cout << solve(0,n,0);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
