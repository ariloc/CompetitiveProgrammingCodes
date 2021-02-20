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

const int TOP = 1e9+5;

int fun (int mid, int s, int d) {
    return mid+min((s-2*mid),(d-mid)/2);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int s,d; cin >> s >> d;

        int top = min(s/2,d);
        int low = 0, high = top;
        while (high-low > 1) { // suponiendo que crafteo una cantidad de palas
            int mid = (high+low)/2;

            if (mid+1 > top || fun(mid,s,d) > fun(mid+1,s,d)) high = mid;
            else low = mid;
        }
        cout << max(fun(high,s,d),fun(low,s,d)) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
