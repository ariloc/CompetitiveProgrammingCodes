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

const int MAXN = 5002;

int arr[MAXN];

int main() {
    int n; scanf("%d",&n);

    int x,y,z;
    puts("? 1 2"); fflush(stdout);
    scanf("%d",&x);
    puts("? 2 3"); fflush(stdout);
    scanf("%d",&y);
    puts("? 1 3"); fflush(stdout);
    scanf("%d",&z);

    arr[0] = (y-z-x)/-2;
    arr[2] = z-arr[0];
    arr[1] = x-arr[0];

    forsn(i,4,n+1) {
        printf("? 1 %d\n",i); fflush(stdout);
        scanf("%d",&arr[i-1]);
        arr[i-1] = arr[i-1]-arr[0];
    }

    printf("! ");
    forn(i,n) printf("%d ",arr[i]);
    puts(""); fflush(stdout);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
s
