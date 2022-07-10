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
typedef long double ld;

const ld INF = 9e18;

ld calc (int p, int a, int b, int c, int d, int k) {
    return p * (sin(a*k + b) + cos(c*k + d) + 2);
}

int main() {
    int p,a,b,c,d,n;
    while (scanf("%d %d %d %d %d %d",&p,&a,&b,&c,&d,&n) != -1) {
        ld max_val = -INF;
        ld ret = 0;
        forsn(i,1,n+1) {
            ld aux = calc(p,a,b,c,d,i);
            if (aux > max_val) max_val = aux;
            if (i) ret = max(ret, max_val - aux);
        }
        printf("%.6Lf\n",ret);
    }

    return 0;
}
