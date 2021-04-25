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

const int MAXN = 105;

int ids[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;

    vi a,b,c;
    switch (n%6) {
        case 0 : a = {6}, b = {5,2}, c = {1,3,4}; break;
        case 2 : a = {}, b = {1}, c = {2}; break;
        case 3 : a = {1}, b = {2}, c = {3}; break;
        case 5 : a = {4}, b = {2,3}, c = {5,1};
        default : break;
    }

    if (a.empty() && b.empty() && c.empty()) cout << "IMPOSSIBLE";
    else {
        int rest = n%6; bool half = false;
        if (!rest) rest += 6;
        while (rest < n) {
            a.pb(rest+3), b.pb(rest+2), c.pb(rest+1);
            if (half) swap(a.back(),c.back());
            rest += 3, half = !half;
        }

        for (auto &i : a) ids[i] = 1;
        for (auto &i : b) ids[i] = 2;
        for (auto &i : c) ids[i] = 3;

        forsn(i,1,n+1) cout << ids[i] << ' ';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!