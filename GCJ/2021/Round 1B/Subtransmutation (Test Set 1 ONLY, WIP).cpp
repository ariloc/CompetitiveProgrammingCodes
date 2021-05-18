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

const int MAXN = 25;
const int MAXC = 50;

int arr[MAXC+5];
ll aux[MAXC+5];

bool posib (int mid, int n) {
    forn(i,n+1) aux[i] = 0;
    aux[mid] = 1;
    dforsn(i,1,mid+1) {
        ll canUse = max(0LL,aux[i]-arr[i]);
        aux[i] -= canUse;
        if (i-1 > 0) aux[i-1] += canUse;
        if (i-2 > 0) aux[i-2] += canUse;
    }
    bool posib = true;
    forsn(i,1,n+1) {
        if (arr[i] > aux[i]) posib = false;
    }
    return posib;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,a,b; cin >> n >> a >> b;
        forn(i,MAXC+5) arr[i] = aux[i] = 0; // double reset
        forn(i,n) cin >> arr[i+1];

        int low = 1, high = MAXC;
        while (high - low > 1) {
            int mid = (high+low)/2;
            if (posib(mid,n)) high = mid;
            else low = mid;
        }

        if (posib(low,n)) high = low;

        cout << "Case #" << o+1 << ": " << high << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!