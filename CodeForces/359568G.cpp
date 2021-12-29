// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/359568/problem/G
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

const int MAXN = 1e6+5;

bitset<MAXN> done;

void criba() {
    for (int i = 4; i < MAXN; i += 2) done[i] = true;
    for (int i = 3; i*i <= MAXN; i += 2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j += i)
                done[j] = true;
}

int main() {
    int n; scanf("%d",&n);

    criba();

    int r = 0;
    forsn(i,2,n+1) if (!done[i]) r++;
    printf("%d",r);

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!