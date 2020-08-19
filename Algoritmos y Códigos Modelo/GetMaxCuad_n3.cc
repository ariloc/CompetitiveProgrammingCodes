#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforr(i, a, b) for(int i = (int)(b-1); i >= (a); i--)
#define dforn(i, n) dforr(i, 0, n)
#define db(v) cerr << #v << " = " << v << endl
#define pb push_back
#define sz(x) ((int)x.size())
#define fst first
#define snd second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
const int MAXN = 1050;

int n, m;
int B[MAXN][MAXN], C[MAXN][MAXN];
int LEFT[MAXN][MAXN], UP[MAXN][MAXN];

int mCuad(int i, int j){
    forn(k, MAXN){
        int ni = i + k, nj = j + k;
        if(ni >= n || nj >= m)return k;
        int reach = min(LEFT[ni][nj], UP[ni][nj]);
        if(reach < k)return k;
    }
    assert(false); // Si el algo llega acá es porque codeé algo como el tuje
}

int main(){
//	freopen("input.txt", "r", stdin);
//  ios :: sync_with_stdio(false); cin.tie(NULL);
    while(scanf("%d %d", &n, &m) >= 1){
        forn(i, n)forn(j, m)scanf("%d", &B[i][j]);
        forn(i, n)forn(j, m)scanf("%d", &LEFT[i][j]);
        forn(i, n)forn(j, m)scanf("%d", &UP[i][j]);

        forn(i, n)forn(j, m)
            C[i][j] = mCuad(i, j);
    }
	return 0;
}
