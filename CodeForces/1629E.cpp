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

const int MAXN = 1005;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

int n;
int grid[MAXN][MAXN];
bool done[MAXN][MAXN];

void checkCell (int i, int j) {
    forn(k,4) {
        int tY = i + Y[k], tX = j + X[k];
        if (tY < 0 || tX < 0 || tY >= n || tX >= n)
            continue;
        done[tY][tX] = true;
    }
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        scanf("%d",&n);
        forn(i,n) forn(j,n) scanf("%d",&grid[i][j]), done[i][j] = 0;

        int v = 0;
        for (int i = ((n%4) < 1); i < n; i += 4) {
            done[0][i] = done[0][i+1] = 1;
            v ^= grid[0][i] ^ grid[0][i+1];
            forn(l,2) checkCell(0,i+l);
        }

        forsn(i,1,n) forn(j,n) {
            bool nope = false;
            forn(k,4) {
                int tY = i + Y[k], tX = j + X[k];
                if (tY < 0 || tX < 0 || tY >= n || tX >= n)
                    continue;
                if (done[tY][tX]) nope = true;
            }
            if (!nope) {
                v ^= grid[i][j];
                checkCell(i,j);
            }
        }

        printf("%d\n",v);
    }

    return 0;
}