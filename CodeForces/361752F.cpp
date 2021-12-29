// Nested Segments
// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361752/problem/F
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

const int MAXN = 2e5+10;

int arr[MAXN],FT[MAXN];

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int st[MAXN], nd[MAXN], rta[MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,2*n) scanf("%d",&arr[i]);
    forn(i,MAXN) st[i] = nd[i] = rta[i] = -1;

    forn(i,2*n) {
        if (st[arr[i]] == -1) st[arr[i]] = i+3;
        else nd[arr[i]] = i+3;
    }

    forn(i,2*n) {
        if (rta[arr[i]] == -1) rta[arr[i]] = getFT(i+3);
        else {
            rta[arr[i]] = getFT(st[arr[i]]) - rta[arr[i]];
            setFT(1,1), setFT(st[arr[i]], -1);
        }
    }

    forn(i,n) printf("%d ",rta[i+1]);

    return 0;
}