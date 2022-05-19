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

const int INF = 2e9;
const int TOP = 1e6;

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int C,M,Y,K;
        C = M = Y = K = INF;
        forn(l,3) {
            int c,m,y,k; scanf("%d %d %d %d",&c,&m,&y,&k);
            C = min(C,c);
            M = min(M,m);
            Y = min(Y,y);
            K = min(K,k);
        }
        
        printf("Case #%d: ",o+1);
        if (C+M+Y+K < TOP) puts("IMPOSSIBLE");
        else {
            if (C+M+Y+K > TOP) C = max(0,C-(C+M+Y+K-TOP));
            if (C+M+Y+K > TOP) M = max(0,M-(C+M+Y+K-TOP));
            if (C+M+Y+K > TOP) Y = max(0,Y-(C+M+Y+K-TOP));
            if (C+M+Y+K > TOP) K = max(0,K-(C+M+Y+K-TOP));
            printf("%d %d %d %d\n",C,M,Y,K);
        }
    }

    return 0;
}
