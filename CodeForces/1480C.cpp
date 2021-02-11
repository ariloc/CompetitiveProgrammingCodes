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
const int INF = 1e9+5;

int arr[MAXN],n,q = 100;

int solve (int l, int r) {
    if (r-l+1 <= q) {
        forsn(i,l,r+1) {
            printf("? %d\n",i);
            fflush(stdout);
            scanf("%d",&arr[i]);
        }
        forsn(i,l,r+1) if (min({arr[i],arr[i-1],arr[i+1]}) == arr[i]) return i;
    }

    printf("? %d\n",r);
    fflush(stdout);
    scanf("%d",&arr[r]);
    printf("? %d\n",r-1);
    fflush(stdout);
    scanf("%d",&arr[r-1]);
    q -= 2;

    if (r == n && arr[r-1] > arr[r]) return r;

    int mid = (l+r)/2;
    printf("? %d\n",mid);
    fflush(stdout);
    scanf("%d",&arr[mid]);
    q--;

    if (arr[mid] > arr[r-1]) return solve(mid,r);
    else {
        printf("? %d\n",mid-1);
        fflush(stdout);
        scanf("%d",&arr[mid-1]);
        q--;

        if (arr[mid-1] < arr[mid]) return solve(l,mid);
        else return solve(mid,r);
    }
}

int main() {
    scanf("%d",&n);
    arr[0] = arr[n+1] = INF;

    printf("! %d",solve(1,n));
    fflush(stdout);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
