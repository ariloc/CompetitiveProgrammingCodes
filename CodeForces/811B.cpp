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

const int MAXN = 1e4+5;
const int INF = 1e9+5;

int arr[MAXN];
int aux[MAXN];
bool notSort[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,n) {
        int x; cin >> x;
        arr[i] = x;
    }


    forn (i,m) {
        int a,b,x; cin >> a >> b >> x; a--; b--; x--;

        int l = 0, r = 0;
        forsn (j,a,b+1) {
            if (j < x and arr[j] > arr[x]) r++;
            if (j > x and arr[j] < arr[x]) l++;
        }

        cout << (abs(r-l) ? "No" : "Yes") << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!