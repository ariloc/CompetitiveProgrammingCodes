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

int const MAXN = 2e5+5;
ll const INF = 1e18;

int arr[MAXN];
ll prodp[MAXN], tad[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d",&arr[i]);

        ll s = 0;
        forn(i,n) tad[i+1] = tad[i] + arr[i], s += arr[i];

        ll prod = 1;
        prodp[0] = 1;
        forn(i,n) prod = (ll)min((__int128)INF, prod * (__int128)arr[i]), prodp[i+1] = prodp[i] * (ll)arr[i];

        if (prod > 2*n-2) {
            int l = 0, r = n-1;
            forn(i,n) if (arr[i] > 1) {
                l = i; break;
            }
            dforn(i,n) if (arr[i] > 1) {
                r = i; break;
            }
            ++l, ++r;
            printf("%d %d\n",l,r);
            continue;
        }
        
        vector<ii> blocks;
        int ind = 0;
        forn(i,n) if (arr[i] > 1) {ind = i; break;}
        forsn(i,ind+1,n) {
            if (arr[i] > 1 && arr[i-1] == 1) ind = i;
            if (arr[i] == 1 && arr[i-1] > 1) blocks.pb({ind,i-1});
        }
        if (arr[n-1] > 1) blocks.pb({ind,n-1});

        ll maxi = s;
        ii rta = {0,0};
        forn(i,blocks.size()) forsn(j,i,blocks.size()) {
            int l = blocks[i].fst, r = blocks[j].snd;
            ll prodaux = prodp[r+1] / prodp[l], saux = tad[r+1] - tad[l];
            ll news = s - saux + prodaux;
            if (news > maxi) maxi = news, rta = {l,r};
        }

        printf("%d %d\n",rta.fst+1,rta.snd+1);
    }
    
    return 0;
}
