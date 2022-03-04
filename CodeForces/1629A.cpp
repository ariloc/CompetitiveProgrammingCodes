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

ii a[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n,k; scanf("%d %d",&n,&k);
        forn(i,n) scanf("%d",&a[i].fst);
        forn(i,n) scanf("%d",&a[i].snd);

        sort(a,a+n);
        forn(i,n) {
            if (a[i].fst > k) break;
            k += a[i].snd;
        }
        printf("%d\n",k);
    }

    return 0;
}