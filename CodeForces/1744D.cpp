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

const int MAXN = 2e5+5;

bitset<MAXN> done;

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);

        forn(i,n) done[i] = false;

        int cnt = 0;
        forn(i,n) {
            int x; scanf("%d",&x);
            while (!(x&1)) cnt++, x >>= 1;
        }

        int op = 0;
        int bits = 31-__builtin_clz(n);
        int st = (1<<bits);

        while (cnt < n && st > 0) {
            int act = st-1;
            while (act < n && cnt < n) {
                if (!done[act]) op++, cnt += bits, done[act] = true;
                act += st;
            }
            st >>= 1, bits--;
        }

        if (cnt < n) printf("-1\n");
        else printf("%d\n",op);
    }

    return 0;
}
