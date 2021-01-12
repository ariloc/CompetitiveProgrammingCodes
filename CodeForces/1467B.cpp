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

const int MAXN = 3e5+2;

int arr[MAXN]; // 1 is hill, 2 is valley
bool typ[MAXN];

bool doesCount (int a, int b, int c) {
    return ( (a > b && c > b) || (a < b && c < b) );
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) typ[j] = 0; // reset
        forn(j,n) cin >> arr[j];
        int cnt = 0, maxD = 0;
        forsn(j,1,n-1) {
            if ((arr[j] > arr[j-1] && arr[j] > arr[j+1])) cnt++, typ[j] = 1;
            if ((arr[j] < arr[j-1] && arr[j] < arr[j+1])) cnt++, typ[j] = 1;
        }
        forsn(j,1,n-1) { // si cambio este
            int meCnt = (typ[j-1] > 0) + (typ[j+1] > 0) + (typ[j] > 0);

            //int aux = arr[j];
            maxD = max(maxD,meCnt-( doesCount(arr[j-1],arr[j-1],arr[j+1]) + (j >= 2 ? doesCount(arr[j-2],arr[j-1],arr[j-1]) : 0) + (j+2 < n ? doesCount(arr[j-1],arr[j+1],arr[j+2]) : 0)));
            maxD = max(maxD,meCnt-( doesCount(arr[j-1],arr[j+1],arr[j+1]) + (j >= 2 ? doesCount(arr[j-2],arr[j-1],arr[j+1]) : 0) + (j+2 < n ? doesCount(arr[j+1],arr[j+1],arr[j+2]) : 0)));
        }
        cout << max(0,cnt-maxD) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
