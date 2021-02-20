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

const int MAXN = 3e4+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];

        int cnt = 0,lst[3] = {0,0,0};
        int eq = n/3;
        forn(i,n) lst[arr[i]%3]++;
        forn(i,n) if (lst[arr[i]%3] > eq) lst[arr[i]%3]--, lst[(arr[i]+1)%3]++, arr[i]++, cnt++;
        forn(i,n) if (lst[arr[i]%3] > eq) lst[arr[i]%3]--, lst[(arr[i]+1)%3]++, arr[i]++, cnt++;
        cout << cnt << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
