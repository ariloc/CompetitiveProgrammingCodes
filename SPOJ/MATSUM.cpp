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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 1030;

int FT[MAXN][MAXN];
int mat[MAXN][MAXN];
int N;

void setFT (int y, int x, int v) {
    y += 3, x += 3;
    for (int i = y; i < N; i += i & -i)
        for (int j = x; j < N; j += j & -j)
            FT[i][j] += v;
}

int getFT (int y, int x) {
    y += 3, x += 3;
    int r = 0;
    for (int i = y; i; i -= i & -i)
        for (int j = x; j; j -= j & -j)
            r += FT[i][j];
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(_,t) {
        int n; cin >> n;
        N = n+5;

        string comm;
        while (cin >> comm) {
            if (comm == "END") break;
            if (comm == "SET") {
                int x,y,num; cin >> x >> y >> num;
                setFT(y,x,num-mat[y][x]);
                mat[y][x] = num;
            }
            else {
                int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
                cout << getFT(y2,x2) - getFT(y2,x1-1) - getFT(y1-1,x2) + getFT(y1-1,x1-1) << '\n';
            }
        }

        forn(i,N) forn(j,N) FT[i][j] = mat[i][j] =  0; // clean
    }
               
    return 0;
}
