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

const int MAXN = 1005;

int ind[MAXN];

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);
        
        forn(i,MAXN) ind[i] = -1;

        forn(i,n) {
            int x; scanf("%d",&x);
            ind[x] = i;
        }
    
        int maxi = -1;
        forn(i,MAXN) forsn(j,i,MAXN)
            if (ind[i] != -1 && ind[j] != -1 && __gcd(i,j) == 1)
                maxi = max(maxi, ind[i] + ind[j] + 2);

        printf("%d\n",maxi);
    }

    return 0;
}
