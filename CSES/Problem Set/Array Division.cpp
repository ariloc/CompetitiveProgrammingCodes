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

const int MAXN = 2e5+2;
const ll HIGH = MAXN*1e9;
const int INF = 1e9+5;

int arr[MAXN],n,k;

int check(ll mid) {
    int ret = 0, cnt = 0; ll sum = 0;
    forn(i,n) {
        if (arr[i] > mid) return INF;
        if (sum+arr[i] > mid) {cnt = 0; ret++; sum = 0;}
        sum += arr[i]; cnt++;
    }
    if (cnt) ret++;
    return ret;
}

int main() {
    scanf("%d %d",&n,&k);
    forn(i,n) scanf("%d",&arr[i]);

    ll low = 1, high = HIGH;
    while (high-low>1) {
        ll mid = low + (high-low)/2LL;
        if (check(mid) <= k) high = mid;
        else low = mid;
    }

    if (check(low) > k) low = high;
    printf("%lld",high);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
