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
#define pc(x) putchar_unlocked(x)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    int n; scanf("%d",&n);

    printf("%d\n",(1<<n)-1);
    forsn(i,1,(1<<n)) {
        int st = (i&(i-1))%3, nd = ((i|(i-1))+1)%3;
        if (!(n&1)) st = (st == 2 ? 1 : st == 1 ? 2 : st), nd = (nd == 2 ? 1 : nd == 1 ? 2 : nd);
        pc(st+1+'0'); pc(' '); pc(nd+1+'0'); pc('\n');
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
