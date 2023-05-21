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
const int INF = 2e9;

struct rango {
    int len,h;

    bool operator< (const rango &o) const {
        return h < o.h;
    }
};

int arr[MAXN], rta[MAXN];
int dpl[MAXN], dpr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n) cin >> arr[i+1];
    arr[0] = arr[n+1] = -INF;

    forsn(i,1,n+1) {int j; for (j = i-1; arr[j] >= arr[i]; j = dpl[j]) {} dpl[i] = j;}
    dforsn(i,1,n+1) {int j; for (j = i+1; arr[j] >= arr[i]; j = dpr[j]) {} dpr[i] = j;}

    vector<rango> upd;
    forsn(i,1,n+1) {
        int h = arr[i];
        int l = dpl[i]+1, r = dpr[i]-1;
        upd.pb({r-l+1,h});
    }

    sort(all(upd),[](const rango &lhs, const rango &rhs){
        return lhs.len < rhs.len;
    });

    int ind = (int)upd.size();
    int maxi = -1;
    dforn(i,n) {
        while (ind-1 >= 0 && upd[ind-1].len >= i+1) 
            maxi = max(maxi, upd[--ind].h);
        rta[i] = maxi;
    }

    forn(i,n) cout << rta[i] << ' ';

    return 0;
}
