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

const int TOP = 1e6+5;
const int TOPP = 1e9+5;

ld calc (ld u, ld d, ld f, ld mid) { // parte de subir
    f /= (ld)100;

    // encontremos el punto en el que la fatiga supera a la subida, y trunquemos ahí
    ld tMid = ll((f+1)/f);
    tMid = min(tMid,mid);

    return max((ld)0,u*tMid - (u*f)*((tMid-1)*tMid)/2) - d*(mid-1);
}

ld calc2 (ld u, ld d, ld f, ld mid) { // incluye bajar
    f /= (ld)100;

    // encontremos el punto en el que la fatiga supera a la subida, y trunquemos ahí
    ld tMid = ll((f+1)/f);
    tMid = min(tMid,mid);

    return max((ld)0,u*tMid - u*f*(tMid-1)*tMid/(ld)2) - d*mid;
}

int main() {
    int h,u,d,f;
    while (scanf("%d %d %d %d",&h,&u,&d,&f) != EOF) {
        if (!h) break;

        // Ternary Search
        int low = 1, high = TOP;
        while (high-low > 1) {
            int mid = (high+low)/2;
            if (calc(u,d,f,mid) < calc(u,d,f,mid+1)) low = mid;
            else high = mid;
        }

        if (calc(u,d,f,low) > calc(u,d,f,high)) high = low;

        if (calc(u,d,f,high) > h) {
            // acá entonces hasta high es binary
            int lo = 1, hi = high;
            while (hi-lo > 1) {
                int mid = (hi+lo)/2;
                if (calc(u,d,f,mid) > h) hi = mid;
                else lo = mid;
            }

            if (calc(u,d,f,lo) <= h) lo = hi;

            printf("success on day %d\n",lo);
        }
        else {
            // desde high, debería ir en caída, entonces es Binary
            int lo = high, hi = TOPP;
            while (hi-lo > 1) {
                int mid = (hi+lo)/2;
                if (calc2(u,d,f,mid) >= 0) lo = mid;
                else hi = mid;
            }
            if (calc2(u,d,f,lo) >= 0) lo = hi;
            printf("failure on day %d\n",lo);
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
