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

const int MAXN = 5005;

ll arr[MAXN], Q[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        forn(i,n) Q[i] = 0; // reset
        forn(i,n) cin >> arr[i];
        ll mov = 0;
        forn(i,n) {
            ll bott = max((ll)i+2,i+arr[i]-Q[i]+1);
            forsn(j,bott,min((ll)n,i+arr[i]+1)) Q[j]++;
            if (bott == i+2) Q[i+1] += 1-arr[i]+Q[i]; // los que sobran
            arr[i] = max(1LL,arr[i]-Q[i]);
            mov += arr[i]-1; // los que quedan para pasarlo a 1
            forsn(j,i+2,min((ll)n,i+arr[i]+1)) Q[j]++;
        }
        cout << mov << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
