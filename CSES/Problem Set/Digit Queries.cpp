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

const int MAXN = 52;

int arr[MAXN];

int main() {
    FAST_IO;

    int q; cin >> q;
    forn(j,q) {
        ll k; cin >> k;

        ll del = 9, cnt = 1, acc = 0, fn = 9;
        while (k >= (acc+del*cnt)) acc += del*cnt, del *= 10LL, cnt++, fn = fn*10 + 9;

        k -= acc;
        ll esimo = (k+cnt-1)/cnt, rest = k%cnt;
        ll num = fn/10+esimo;
        if (rest) rest = cnt-rest;

        while (rest--) num /= 10;
        cout << num%10 << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
