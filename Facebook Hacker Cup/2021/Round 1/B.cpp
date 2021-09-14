#include <bits/stdc++.h>
    
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
    
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
    
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 52;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

int mat[MAXN][MAXN];

int main() {
    FAST_IO;

    freopen("traffic_control_input.txt","r",stdin);
    freopen("salida.txt","w",stdout);

    int t; cin >> t;
    forn(o,t) {
        int n,m,a,b; cin >> n >> m >> a >> b;

        int dist = n+m-1;

        if (dist > b || dist > a) cout << "Case #" << o+1 << ": Impossible\n";
        else {
            forn(i,n) forn(j,m) mat[i][j] = 1; // init minimo
            mat[n-1][m-1] = a-dist+1;
            mat[0][m-1] = b-dist+1;
            cout << "Case #" << o+1 << ": Possible\n";
            forn(i,n) {forn(j,m) cout << mat[i][j] << ' '; cout << '\n';}
        }
    }

    return 0;
}