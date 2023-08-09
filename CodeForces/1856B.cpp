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

int const MAXN = 1e5+5;

int arr[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d",&arr[i]);

        ll s = 0;
        forn(i,n) s += arr[i];

        int cnt1 = 0;
        forn(i,n) cnt1 += (arr[i] == 1);

        if (cnt1*2LL > s) {
            printf("NO\n"); continue;
        }
        s -= cnt1 * 2LL;

        if ((n-cnt1) > s) {
            printf("NO\n"); continue;
        }

        int dist1 = -1;
        forn(i,n) if (arr[i] != 1) dist1 = arr[i];

        if ((n-cnt1) == 1 && dist1 == s) {
            printf("NO\n"); continue;
        }

        printf("YES\n");
    }

    return 0;
}
