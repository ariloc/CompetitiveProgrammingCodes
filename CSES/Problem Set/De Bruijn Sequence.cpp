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

const int MAXN = 15;

int n; vi way;
bitset<(1<<MAXN)> done;

void dfs(int st) { // solve Eulerian Cycle in Graph of k^(n-1) nodes
    forn(i,2) {
        int v = (st<<1)+i;
        if (done[v]) continue;
        done[v] = true; dfs(v & (~(1<<(n-1)))); // turn off bit
        putchar_unlocked(i+'0');
    }
}

int main() {
    scanf("%d",&n);
    dfs(0); forn(i,n-1) putchar_unlocked('0');

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
