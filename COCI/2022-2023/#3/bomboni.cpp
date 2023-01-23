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

const int MAXN = 505;
const int MOD = 998244353;
const int X[] = {0,-1};
const int Y[] = {-1,0};

int field[MAXN][MAXN];
map<vi,int> dp[MAXN][MAXN];

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    int n,K; scanf("%d %d",&n,&K);
    forn(i,n) forn(j,n) scanf("%d",&field[i][j]);

    map<int,int> F;
    for (int i = 2; i*i <= K; i++) 
        while (!(K%i)) F[i]++, K /= i;
    if (K > 1) F[K]++;

    vector<ii> fact;
    for (auto &i : F) fact.pb(i);

    dp[0][1][vi((int)fact.size(),0)] = 1;
    forsn(i,1,n+1) forsn(j,1,n+1) {
        if (field[i-1][j-1] == -1) continue;

        vi myvals;
        int aux = field[i-1][j-1];
        for (auto &k : fact) {
            int cnt = 0;
            while (!(aux%k.fst)) cnt++, aux /= k.fst;
            myvals.pb(cnt);
        }

        forn(k,2) {
            int tX = j + X[k], tY = i + Y[k];
            if (field[tY-1][tX-1] == -1) continue;

            for (auto &l : dp[tY][tX]) {
                vi newkey = l.fst;

                forn(w,newkey.size()) {
                    newkey[w] = min(newkey[w]+myvals[w], fact[w].snd);
                }

                dp[i][j][newkey] = sumMod(dp[i][j][newkey], l.snd);
            }
        }
    }

    vi finalComb;
    for (auto &i : fact) finalComb.pb(i.snd);

    printf("%d",dp[n][n][finalComb]);
   
    return 0;
}
