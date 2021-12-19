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

const int MAXN = 1e5+5;

int baches[MAXN];

bool canCover (int len, int k, int n) {
    forn(i,n)
        if (baches[i]) {
            if (k <= 0) return false;
            else --k, i += len-1;
        }
    return true;
}

int main() {
    int n,k; scanf("%d %d",&n,&k);
    forn(i,n) scanf("%d",&baches[i]);

    int low = -1, high = n;
    while (high-low > 1) {
        int mid = (high+low)/2;
        if (canCover(mid,k,n)) high = mid;
        else low = mid;
    }

    printf("%d",high);
    
    return 0;
}