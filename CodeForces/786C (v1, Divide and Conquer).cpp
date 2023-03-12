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

const int MAXN = 1e5+5;

int arr[MAXN], rta[MAXN], n;
bitset<MAXN> done;

int calc (int k) {
    if (rta[k]) return rta[k];

    vi toreset;
    int ret = 0, cols = 0;
    forn(i,n)  {
        if (!done[arr[i]]) done[arr[i]] = true, cols++, toreset.pb(arr[i]);
        if (cols > k) {
            int last = toreset.back();
            while (!toreset.empty()) done[toreset.back()] = false, toreset.pop_back();
            done[last] = true, toreset.pb(last), cols = 1;
            ret++;
        }
    }
    for (auto &i : toreset) done[i] = false;
    return ret+1;
}

void solve (int l, int r) {
    if (r-l <= 1) {
        rta[l] = calc(l);
        return;
    }
    rta[l] = calc(l);
    rta[r] = calc(r);

    int mid = (l+r)/2;
    rta[mid] = calc(mid);

    if (rta[l] != rta[mid]) solve(l,mid);
    else forsn(i,l,mid) rta[i] = rta[l];

    if (rta[r] != rta[mid]) solve(mid,r);
    else forsn(i,mid,r) rta[i] = rta[mid];
}

int main() {
    scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    solve(1,n);

    forsn(i,1,n+1) printf("%d ",rta[i]);

    return 0;
}
