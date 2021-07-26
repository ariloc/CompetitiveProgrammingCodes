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

const int MAXN = 40;

int arr[MAXN],n,m;
set<int> sums,sums2;
int rta = 0;

void recur (int pos, int accSum, int top, set<int> &toAdd) {
    toAdd.insert(accSum%m);
    if (pos >= top) return;

    recur(pos+1,accSum,top,toAdd);
    recur(pos+1,(accSum+arr[pos])%m,top,toAdd);
}

int main() {
    scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d",&arr[i]);

    if (n == 1) return cout << arr[0]%m, 0;

    recur(0,0,n/2,sums);
    recur(n/2,0,n,sums2);

    for (auto &i : sums2) {
        int dif = m-i-1;
        auto it = prev(sums.upper_bound(dif));
        rta = max(rta, i + *it);
    }

    cout << rta;    

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!