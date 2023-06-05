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

const int MAXN = 260;

int mat[MAXN][MAXN],n,m;
int FT[MAXN];

void setFT (int p, int v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int updated (int v, vi &pts) {
    return upper_bound(all(pts),v)-pts.begin()-1;
}

int main() {
    scanf("%d %d",&n,&m);
    forn(i,n) forn(j,m) scanf("%d",&mat[i+1][j+1]);

    int a,b; scanf("%d %d",&a,&b);

    int cnt = 0;
    forsn(i,1,n+1) {
        vi sums(m,0);
        dforsn(j,1,i+1) {
            int acc = 0;
            vi vals, histo;
            vals.pb(0);
            forsn(k,1,m+1) {
                sums[k-1] += mat[j][k];
                int v = sums[k-1];
                acc += v;
                vals.pb(acc);
                histo.pb(acc);
                // cnt += query(cur,0,acc-a+1+SHIFT).v - query(cur,0,acc-b+SHIFT).v;
            }
            sort(all(vals));
            vals.erase(unique(all(vals)),vals.end());

            forn(o,MAXN) FT[o] = 0;
            setFT(updated(0,vals),1);
            for (auto &k : histo) {
                cnt += getFT(updated(k-a, vals)) - getFT(updated(k-b-1, vals));
                setFT(updated(k,vals),1);
            }
        }
    }

    printf("%d",cnt);

    return 0;
}
