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

int const MAXC = 59049;
int const MAXD = 10;
int const INF = 2e9;
int const MAXS = 2005;
int const SHIFT = 1000;

int sides[MAXD];
int pot3[MAXD+1];
int bst[1<<MAXD];
bool dp[MAXD][MAXS];
int n;

int main() {
    pot3[0] = 1;
    forsn(i,1,MAXD+1) pot3[i] = pot3[i-1] * 3;

    scanf("%d",&n);

    forn(i,n) scanf("%d",&sides[i]);

    forsn(i,1,1<<n) {
        vi elem;
        forn(j,n) if (i&(1<<j)) elem.pb(sides[j]);
        int m = (int)elem.size();

        forn(j,m) forn(k,MAXS) dp[j][k] = 0;

        dp[0][SHIFT+elem[0]] = 1;
        dp[0][SHIFT-elem[0]] = 1;
        forsn(j,1,elem.size()) forn(k,MAXS) {
            if (k-elem[j] >= 0) dp[j][k] |= dp[j-1][k-elem[j]];
            if (k+elem[j] < MAXS) dp[j][k] |= dp[j-1][k+elem[j]];
        }

        int rta = INF;
        forsn(j,SHIFT,MAXS) if (dp[m-1][j]) rta = min(rta,j-SHIFT);
        bst[i] = rta;
    }

    int area = INF;
    forn(i,MAXC) {
        int mks[] = {0,0,0};
        forn(k,n) {
            int dig = (i/pot3[k])%3;
            mks[dig] |= (1<<k);
        }

        int a = bst[mks[0]], b = bst[mks[1]], c = bst[mks[2]];
        int perim = (a+b+c);
        int t1 = (a+b-c);
        int t2 = (a-b+c);
        int t3 = (-a+b+c);
        int aux = perim * t1 * t2 * t3;
        if (a >= 0 && b >= 0 && c >= 0 && aux >= 0)
            area = min(area, aux);
    }

    printf("%.10f",sqrt(area/(double)16));
    
    return 0;
}
