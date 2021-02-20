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
const int INF = 1e9+5;
const ll TOP = 2e9+5;

int arr[MAXN];
map<ll,int> prefs;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,m; cin >> n >> m;

        prefs.clear(); // reset

        forn(i,n) cin >> arr[i];

        ll acc = 0, top = 0;
        forn(i,n) {
            acc += arr[i];
            top = max(top,acc); // si antes ya tengo uno mejor, no tengo por qué poner uno peor
            if (top == acc && !prefs.count(acc)) prefs[acc] = i; // primeros prefijos
        }

        /// COMO QUE ME HABÍA CONFUNDIDO QUE EL PROBLEMA ERA SI ERA IGUAL A X... huh

        prefs[0] = 0; // aux
        forn(i,m) {
            int x; cin >> x;

            if (acc <= 0) { // no me queda otra que sea un prefijo
                auto it = prefs.lower_bound(x);
                if (it == prefs.end()) cout << "-1 ";
                else cout << (*it).snd << ' ';
                continue;
            }

            ll highP = (*prefs.rbegin()).fst;
            ll neededR = (max(0LL,x-highP) + acc - 1)/acc; // es ceil
            cout << max(0LL,(neededR*n - 1)) + (*(prefs.lower_bound(x-acc*neededR))).snd + (neededR > 0) << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
