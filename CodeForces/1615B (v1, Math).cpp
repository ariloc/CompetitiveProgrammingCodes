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

const int INF = 2e9;

int onUpTo (int bit, int x) {
    if (x <= ((1<<(bit+1))-1))
        return max(0, x-(1<<bit)+1);
    return (1<<bit) * (x >> (bit+1)) + max(0, (x -  ((x & (~((1<<(bit+1))-1)) ) | (1<<bit)) + 1));
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int l,r; scanf("%d %d",&l,&r);
        
        int rta = INF;
        int aux = r, cnt = 0;
        while (aux) {
            rta = min(rta, (r-l+1) - onUpTo(cnt,r) + onUpTo(cnt,l-1));
            cnt++, aux >>= 1;
        }

        printf("%d\n",rta);
    }

    return 0;
}