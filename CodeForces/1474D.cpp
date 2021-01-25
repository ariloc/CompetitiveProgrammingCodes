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

const int MAXN = 2e5+10;

int arr[MAXN], dpL[MAXN], dpR[MAXN];
bool posibL[MAXN], posibR[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) cin >> arr[j+1];
        forn(j,n+5) dpL[j] = dpR[j] = posibL[j] = posibR[j] = 0;

        posibL[0] = posibR[n+1] = true;
        dforsn(j,1,n+1) {dpR[j] = (arr[j] - dpR[j+1]); if (dpR[j] < 0) posibR[j] = false; else posibR[j] = posibR[j+1];}
        forsn(j,1,n+1) {dpL[j] = (arr[j] - dpL[j-1]); if (dpL[j] < 0) posibL[j] = false; else posibL[j] = posibL[j-1];}

        bool posib = false;
        forsn(j,1,n) {
            if (!posibL[j-1] || !posibR[j+2]) continue;
            forn(k,2) {
                swap(arr[j],arr[j+1]);
                if (arr[j]-dpL[j-1] == arr[j+1]-dpR[j+2] && (arr[j]-dpL[j-1]) >= 0) posib = true;
            }
        }

        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
