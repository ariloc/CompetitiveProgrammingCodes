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

set<int> arr;

int main() {
    int n,q; scanf("%d %d",&n,&q);
    forn(i,q) {
        int typ; scanf("%d",&typ);
        int p; scanf("%d",&p); p--;
        if (typ == 1) {
            arr.insert(p);
        }
        else {
            auto it = arr.lower_bound(p);
            if (it == arr.end()) printf("-1\n");
            else printf("%d\n",(*it)+1);
        }
    }

    return 0;
}
