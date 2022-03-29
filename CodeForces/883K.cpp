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
typedef long double ld;

const int MAXN = 2e5+5;
const int INF = 2e9;

int nd_w[MAXN];
ii inp[MAXN];

int main() {
    int n; scanf("%d",&n);

    forn(i,n) {
        int s,g; scanf("%d %d",&s,&g);
        inp[i] = {s,g};
    }

    int act = INF;
    forn(i,n) {
        if (++act > inp[i].fst + inp[i].snd)
            act = inp[i].fst + inp[i].snd;
        nd_w[i] = act;
    }

    act = INF;
    dforn(i,n) {
        if (++act > inp[i].fst + inp[i].snd)
            act = inp[i].fst + inp[i].snd;
        nd_w[i] = min(nd_w[i],act);
    }

    ll acc = 0;
    forn(i,n) {
        if ((i && abs(nd_w[i]-nd_w[i-1]) > 1) || 
            nd_w[i] < inp[i].fst || nd_w[i] > inp[i].fst + inp[i].snd)
                return printf("-1"), 0;
        acc += nd_w[i]-inp[i].fst;
    }

    printf("%lld\n",acc);
    forn(i,n) printf("%d ",nd_w[i]);

    return 0;
}