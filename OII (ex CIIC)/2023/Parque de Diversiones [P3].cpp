#include <algorithm>
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

int const MAXN = 1e6+5;

vector<vi> mat;
ll rta[MAXN],xp[MAXN];
int lastind[MAXN];
int n,m;
vector<ll> cand;

int main() {
    scanf("%d %d",&n,&m);

    mat.assign(n,{});

    forn(i,n) forn(j,m) {
        int x; scanf("%d",&x);
        mat[i].pb(x);
    }

    forn(i,n) {
        int ind = 0;
        forn(j,m) if (mat[i][j]) ind = j;
        lastind[i] = ind;
    }

    forn(j,m) {
        cand.clear();
        forn(i,n) {
            if (j == lastind[i]) {
                ll mult = (-xp[i]) / (ll)mat[i][j];
                if (mult >= 0 && (xp[i] + mult * mat[i][j]) == 0) {
                    cand.pb(mult);
                }
            }
        }
        sort(all(cand));
        cand.erase(unique(all(cand)),cand.end());
        int mex = 0;
        forn(i,cand.size()) {
            if (cand[i] != mex) break;
            mex++;
        }
        
        rta[j] = mex;
        forn(i,n) xp[i] += rta[j] * (ll)mat[i][j];
    }

    forn(i,m) printf("%lld ",rta[i]);
                     
    return 0;
}
