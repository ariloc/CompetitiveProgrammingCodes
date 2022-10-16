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
typedef long double ld;

const int MAXN = 1e5+5;

int perm[MAXN], rta[MAXN];

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);

        set<int> avail;
        forn(i,n) avail.insert(i+1), rta[i] = 1;

        forn(i,n) scanf("%d",&perm[i]);

        dforsn(i,1,n) {
            if (perm[i] < perm[i-1]) {
                int dif = perm[i-1]-perm[i];

                auto it = avail.lower_bound(dif);
                if (it == avail.end()) it = prev(it);

                auto e = *it;
                rta[e-1] = i+1;
                avail.erase(it);
            }
        }

        forn(i,n) printf("%d ", rta[i]);
        puts("");
    }

    return 0;
}
