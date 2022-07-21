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

const int MAXN = 4e5+5;

int arr[MAXN];
set<ii> byMax;
map<int,int> byNum;

void update (int num, int add) {
    int cnt = byNum[num] += add;
    byMax.erase({cnt-add,num});
    if (cnt > 0)
        byMax.insert({cnt,num});
    else byNum.erase(num);
}

int main() {
    int n,k; scanf("%d %d",&n,&k);
    forn(i,n) scanf("%d",&arr[i]);

    ll rta = 0;
    int r = 0;
    forn(l,n) {
        while (r < n && (byMax.empty() || (*byMax.rbegin()).fst < k))
            update(arr[r++],1);

        if (!byMax.empty() && (*byMax.rbegin()).fst >= k)
            rta += (n-r+1);

        update(arr[l],-1);
    }

    printf("%lld",rta);

    return 0;
}
