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

int arr[MAXN];
ii arrind[MAXN];
bitset<MAXN> present, inrta;
vector<ii> cuts;
vi rta;

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d",&arr[i]);

    forn(i,n) arrind[i] = {arr[i],i};

    dforn(i,n) {
        if (!present[arr[i]])
            cuts.pb({arr[i],i+1}); // from i+1, arr[i] is absent
        present[arr[i]] = true;
    }

    reverse(all(cuts));

    int ind = 0, last = -1;
    priority_queue<ii,vector<ii>,greater<ii>> Q;
    int actadded = cuts[0].snd;
    forn(i,actadded) Q.push(arrind[i]);
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();
        if (e.snd <= last) continue;
        if (inrta[e.fst]) continue;

        rta.pb(e.fst);
        inrta[e.fst] = true;
        last = e.snd;

        if (e.fst == cuts[ind].fst) {
            while (ind < (int)cuts.size() && inrta[cuts[ind].fst]) {
                ind++;
                forsn(i,actadded,cuts[ind].snd)
                    Q.push(arrind[i]);
                actadded = cuts[ind].snd;
            }
        }
    }

    for (auto &i : rta) printf("%d ",i);

    return 0;
}
