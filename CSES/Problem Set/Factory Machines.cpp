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

const int MAXN = 2e5+5;
const ll INF = 1e18;

int prod[MAXN];
int n,t;

bool check(ll mid) {
    ll posib = 0;
    forn(i,n) {
        posib += mid/(ll)prod[i];
        if (posib >= t) return true;
    }
    return false;
}

int main() {
    scanf("%d %d",&n,&t);

    forn(i,n) scanf("%d",&prod[i]);

    ll low = 0, high = INF;
    while (high-low > 1) {
        ll mid = low + (high-low)/2;
        if (check(mid)) high = mid;
        else low = mid;
    }

    if (check(low)) high = low;
    printf("%lld",high);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
