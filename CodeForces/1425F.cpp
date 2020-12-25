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

const int MAXN = 1005;

int TAd[MAXN];

int main() {
    int n; scanf("%d",&n);

    forsn(i,1,n) {
        printf("? 1 %d\n",i+1); fflush(stdout);
        scanf("%d",&TAd[i+1]);
    }

    printf("? 2 %d\n",n); fflush(stdout);
    int aux; scanf("%d",&aux);
    TAd[1] = TAd[n] - aux;

    printf("! ");
    forsn(i,1,n+1) printf("%d ",TAd[i]-TAd[i-1]);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
