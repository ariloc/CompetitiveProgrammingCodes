#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
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
typedef  double ld;
typedef pair<int,int> ii;

const int MAXN = 3e5+2;
const ld EPS = 1e-6;

ld cam[MAXN],rep[MAXN];

int main() {
    int m,n,r; scanf("%d %d %d",&m,&n,&r);
    forn(i,m) scanf("%lf",&cam[i]);
    forn(i,n) scanf("%lf",&rep[i]);

    int prv = 0;
    ld s = 0;
    forn(i,n) {
        int l = -1, h = m-1;
        while (h-l > 1) {
            int mm = (h+l)/2;
            if (cam[mm] < rep[i]) l = mm;
            else h = mm;
        }

        int ind = h;

        if (ind >= m || hypotl(1,abs(cam[ind]-rep[i]))-r > EPS) ind--;

        if (prv <= ind) {
            int low = prv, high = ind;
            while (high-low > 1) {
                int mid = (high+low)/2;
                if (hypotl(1,abs(cam[mid]-rep[i]))-r > EPS) low = mid;
                else high = mid;
            }
            if (r-hypotl(1,abs(cam[low]-rep[i])) >= -EPS) high = low;
            s += abs(cam[prv]-cam[high]), prv = high;
        }
        else {
            int low = ind, high = prv;
            while (high-low > 1) {
                int mid = (high+low)/2;
                if (r-hypotl(1,abs(cam[mid]-rep[i])) >= -EPS) low = mid;
                else high = mid;
            }
            if (r-hypotl(1,abs(cam[high]-rep[i])) >= -EPS) low = high;
            s += abs(cam[prv]-cam[low]), prv = low;
        }
    }

    printf("%.10lf",s);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
