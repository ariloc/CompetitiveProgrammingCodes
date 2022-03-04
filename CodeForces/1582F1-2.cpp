#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9+5;
const int MAXN = 1e6+5;
const int MAXVS = 5005;
const int MAXV = (1<<13) + 20;

int min_ind[MAXV];
int arr[MAXN];
vi aparic[MAXVS];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    forn(i,n) aparic[arr[i]].pb(i);
    forn(i,MAXV) min_ind[i] = INF;

    min_ind[0] = -1;
    forn(i,MAXVS) forn(j,MAXV-20) { // llego a un valor i del array, formo j
        if (aparic[i].empty()) continue;

        int prv = i^j;
        auto it = upper_bound(all(aparic[i]),min_ind[prv]);
        if (it == aparic[i].end()) continue;
        min_ind[j] = min(min_ind[j],*it);
    }

    vi rta;
    forn(i,MAXV)
        if (min_ind[i] != INF) rta.pb(i);

    printf("%d\n",(int)rta.size());
    for (auto &i : rta)
        printf("%d ",i);

    return 0;
}