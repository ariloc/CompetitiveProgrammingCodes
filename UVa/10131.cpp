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

int const MAXN = 1005;

struct elephant {
    int w,s,id;

    bool operator< (const elephant &o) const {
        if (w != o.w) return w < o.w;
        return s < o.s;
    }
};

vector<elephant> eleph;
int dp[MAXN], P[MAXN];

int main() {
    int w,s,n = 0;
    while (scanf("%d %d",&w,&s) != -1) {
        eleph.pb({w,s,++n});
    }

    sort(all(eleph));

    forn(i,n) dp[i] = 1, P[i] = -1;
    int maxi = 1, ind = 0;
    forn(i,n) forsn(j,i+1,n) {
        if (eleph[i].w < eleph[j].w && eleph[i].s > eleph[j].s && dp[i]+1 > dp[j]) {
            dp[j] = dp[i]+1;
            P[j] = i;
            if (dp[j] > maxi) maxi = dp[j], ind = j;
        }
    }

    vi rta;
    int aux = ind;
    while (aux != -1)
        rta.pb(eleph[aux].id), aux = P[aux];
    reverse(all(rta));

    printf("%d\n",maxi);
    for (auto &i : rta) printf("%d\n",i);
       
    return 0;
}
