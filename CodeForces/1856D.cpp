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

int query (int l, int r) {
    printf("? %d %d\n",l+1,r+1);
    fflush(stdout);
    int x; scanf("%d",&x);
    if (x == -1) exit(0);
    return x;
}

void answer (int x) {
    printf("! %d\n",x+1);
    fflush(stdout);
}

int solve (int l, int r) {
    if (r-l <= 1) return l;

    int mid = (l+r)/2;
    int mxl = solve(l,mid);
    int mxr = solve(mid,r);

    if (mxr-mxl <= 1) {
        int aux = query(mxl,mxl+1);
        if (aux) return mxl;
        return mxl+1;
    }

    int ql = query(mxl,mxr-1), qr = query(mxl,mxr);
    if (ql == qr) return mxr;
    return mxl;
}

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);
        answer(solve(0,n));
    }
    
    return 0;
}
