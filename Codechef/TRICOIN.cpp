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

const int MAXV = 50000;

int calc (int n) {
    return n*(ll)(n+1)/2LL;
}

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int x; scanf("%d",&x);

        int low = 1, high = MAXV;
        while (high-low > 1) {
            int mid = (high+low)/2;
            if (calc(mid) <= x) low = mid;
            else high = mid;
        }

        printf("%d\n",low);
    }
  
    return 0;
}
