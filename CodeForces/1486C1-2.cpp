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

bool query (int l, int r, int v) {
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int x; scanf("%d",&x);
    return (x == v);
}

int main() {
    int n; scanf("%d",&n);

    printf("? 1 %d\n",n);
    fflush(stdout);
    int aux; scanf("%d",&aux);

    if (aux == 1) goto OUT;
    printf("? 1 %d\n",aux);
    fflush(stdout);
    int x; scanf("%d",&x);

    if (x == aux) {
        int low = 1, high = aux;
        while (high-low > 1) {
            int mid = (high+low)/2;

            if (query(mid,aux,aux)) low = mid;
            else high = mid;
        }
        printf("! %d\n",low); fflush(stdout);
    }
    else {
        OUT:
        int low = aux, high = n;
        while (high-low > 1) {
            int mid = (high+low)/2;

            if (query(aux,mid,aux)) high = mid;
            else low = mid;
        }
        printf("! %d\n",high); fflush(stdout);
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
