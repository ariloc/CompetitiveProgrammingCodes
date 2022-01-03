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

const int MAXN = 2e5+5;
const int INF = 2e9;

ii arr[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d %d",&arr[i].fst,&arr[i].snd);

        sort(arr,arr+n);

        set<ii> byCost;
        multiset<int> added;
        forn(i,n) byCost.insert({arr[i].snd, i});
        
        int idx = 0;
        ll rta = 0;
        while (!byCost.empty()) {
            while (idx < n && arr[idx].fst <= (n-(int)byCost.size())) {
                auto it = byCost.find({arr[idx].snd, idx});
                if (it != byCost.end()) byCost.erase(it);
                else added.insert(arr[idx].snd);
                idx++;
            }
            if (!byCost.empty()) {
                if (!added.empty())
                    rta -= (*added.rbegin()), added.erase(prev(added.end()));
                auto it_cheap = byCost.begin();
                auto aux = *it_cheap;
                rta += aux.fst;
                byCost.erase(it_cheap);
            }
        }

        printf("%lld\n",rta);
    }
    
    return 0;
}