// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/359568/problem/N
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

const int MAXN = 1e5+5;

int arr[MAXN];
set<ii> ptos;

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]), ptos.insert({arr[i],i});

    int m; scanf("%d",&m);
    forn(o,m) {
        char typ; scanf(" %c",&typ);
        if (typ == 'A') {
            int i,x; scanf("%d %d",&i,&x); i--;
            ptos.erase({arr[i],i});
            arr[i] += x;
            ptos.insert({arr[i],i});
        }
        else {
            auto it = prev(ptos.end());
            forn(k,3) printf("%d ",(*it).snd + 1), it--;
            puts("");
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!