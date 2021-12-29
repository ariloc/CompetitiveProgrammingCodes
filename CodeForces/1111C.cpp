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

const int MAXN = 1e5+5;

int pers[MAXN];
int n,k,A,B;

ll solve (int l, int r) {
    int l_ind = lower_bound(pers,pers+k,l) - pers;
    int r_ind = lower_bound(pers,pers+k,r) - pers;
    int cnt = r_ind - l_ind;
    if (!cnt) return A;
    if (r - l <= 1) return (ll)B * cnt * (r-l);

    int mid = (l+r)/2;
    return min((ll)B * cnt * (r-l), solve(l,mid) + solve(mid,r));
}

int main() {
    scanf("%d %d %d %d",&n,&k,&A,&B);
    forn(i,k) scanf("%d",&pers[i]), pers[i]--;

    sort(pers,pers+k);

    printf("%lld", solve(0, 1<<n));

    return 0;
}