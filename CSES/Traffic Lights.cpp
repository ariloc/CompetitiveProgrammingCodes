#include <bits/stdc++.h>

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

const int INF = 1e9;
const int MAXN = 2e5+2;

int arr[MAXN], rta[MAXN];
set<int> street;

int main() {
    int x,n; scanf("%d %d",&x,&n);

    forn (i,n) {int l; scanf("%d",&l); street.insert(l); arr[i] = l;}

    int best = max(*street.begin(),x-*prev(street.end()));
    for (auto i = next(street.begin()); i != street.end(); i++) {
        best = max(best, *i-*prev(i));
    }

    rta[n-1] = best;
    dforsn (i,1,n) {
        auto it = street.lower_bound(arr[i]);
        int bef = 0, post = x;
        if (it != street.begin()) bef = *prev(it);
        if (next(it) != street.end()) post = *next(it);

        rta[i-1] = max(rta[i],post-bef);
        street.erase(it);
    }

    forn (i,n) printf("%d ",rta[i]);

    return 0;
}
