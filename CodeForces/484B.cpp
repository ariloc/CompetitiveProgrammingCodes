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

const int MAXN = 2e5+5;
const int MAXAi = 1e6+5;

int arr[MAXN];
bitset<MAXAi> done;

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    sort(arr,arr+n);

    int maxi = 0;
    forn(i,n) {
        int x = arr[i];
        if (!done[x]) {
            done[x] = true;
            
            int j = x;
            do {
                j += x;

                int ind = lower_bound(arr,arr+n,j)-arr-1; // busco el más próximo atrás mío
                if (ind >= 0 && arr[ind] >= x && j-arr[ind] < x)
                    maxi = max(maxi, arr[ind]-j+x);
                /*if (ind >= 0 && arr[ind] >= x)
                    maxi = max(maxi, arr[ind]%x);*/
            } while(j < MAXAi);

        }
    }

    cout << maxi;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!