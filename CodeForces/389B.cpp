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

const int MAXN = 105;
const int X[] = {0,0,-1,1,0};
const int Y[] = {0,1,1,1,2};

char board[MAXN][MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%s",board[i]);

    forn(i,n) forn(j,n)
        if (board[i][j] == '#')
            forn(k,5) {
                int tY = i + Y[k], tX = j + X[k];
                if (tY < 0 || tX < 0 || tY >= n || tX >= n || board[tY][tX] != '#')
                    return printf("NO"), 0;
                board[tY][tX] = '.';
            }

    printf("YES");

    return 0;
}