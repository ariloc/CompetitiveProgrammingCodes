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

const int MAXN = 3e5+5;
const int MAXV = 1e9;
const ll INF = 9e18;

int arr[MAXN],N,K;
ll dpl[MAXN], dpr[MAXN];

bool calc (ll s) {
    priority_queue<int> Q,Q2;
    ll acc = 0;
    forn(i,N) {
        Q.push(arr[i]);
        acc += arr[i];
        while (!Q.empty() && acc > s) acc -= Q.top(), Q.pop();
        dpl[i] = (int)Q.size();
    }
    acc = 0;
    dforn(i,N) {
        Q2.push(arr[i]);
        acc += arr[i];
        while (!Q2.empty() && acc > s) acc -= Q2.top(), Q2.pop();
        dpr[i] = (int)Q2.size();
    }

    if (dpl[N-1] >= K) return true;

    forn(i,N-1) {
        if (dpl[i]+dpr[i+1] >= K)
            return true;
    }
   
    return false;
}

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        scanf("%d %d",&N,&K);

        forn(i,N) scanf("%d",&arr[i]);

        ll low = -1, high = (ll)N*MAXV;
        while (high - low > 1) {
            ll mid = (high+low)/2LL;
            if (calc(mid)) high = mid;
            else low = mid;
        }

        printf("%lld\n", high);
    }


    return 0;
}
