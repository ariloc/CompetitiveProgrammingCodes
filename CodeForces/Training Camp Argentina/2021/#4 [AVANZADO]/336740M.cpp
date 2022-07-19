// Statement: https://codeforces.com/group/gXivUSZQpn/contest/336740/problem/M
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

const int MAXN = 40005;

int C[2][MAXN];
int C_full[MAXN];

int main() {
    int n,m; scanf("%d %d",&n,&m);

    C[0][0] = 1;
    forsn(N,1,n+1) {
        C[N&1][0] = 1;
        forsn(K,1,N+1)
            C[N&1][K] = (C[1^(N&1)][K-1] + C[1^(N&1)][K])%m;
    }

    forn(i,n+1) C_full[i] = C[n&1][i]; // lo copio

    // tabla aditiva
    forsn(i,1,n+1) C_full[i] = (C_full[i-1] + C_full[i])%m;

    int q; scanf("%d",&q);
    forn(i,q) {
        int li,ri; scanf("%d %d",&li,&ri);
        printf("%d\n",(C_full[ri]-(li ? C_full[li-1] : 0)+m)%m);
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!